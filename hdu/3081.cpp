#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 110;
int edge[N][N], match[N], vis[N], fa[N];
int n, m, f, t;
int find(int x) {
    return fa[x] = (fa[x]==x ? x: find(fa[x]));
}
bool dfs(int u) {
    for(int v = 1; v <= n; v ++) {
        if(edge[u][v] && !vis[v]) {
            vis[v] = 1;
            if(match[v] == -1 || dfs(match[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m>>f;
        for(int i = 1; i <= n; i ++) fa[i] = i;
        memset(edge, 0, sizeof(edge));
        int u, v;
        for(int i = 1; i <= m; i ++) {
            cin>>u>>v;
            edge[u][v] = 1;
        }
        for(int i = 1; i <= f; i ++) {
            cin>>u>>v;
            fa[find(u)] = find(v);
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(find(i)==find(j)) {
                    for(int k = 1; k <= n; k ++) {
                        if(edge[i][k])edge[j][k] = 1;
                    }
                }
            }
        }
        int ans = 0;
        while(1) {
            int res = 0;
            memset(match, -1, sizeof(match));
            for(int i = 1; i <= n; i ++) {
                memset(vis, 0, sizeof(vis));
                if(dfs(i)) res++;
            }
            if(res < n) break;
            ans++;
            for(int i = 1; i <= n; i ++) {
                if(match[i] != -1) {
                    edge[match[i]][i] = 0;
                }
            }
            // for(int i = 1; i <= n; i ++) {
            //     for(int j = 1; j <= n; j ++) printf("%d ", edge[i][j]);
            //     printf("\n");
            // }
        }
        printf("%d\n",ans);
    }
    return 0;
}
