
//暴力做法不行，一定会超时
/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> vs[110];
int ans, m, n, l, r, vis[110], tmp;
void dfs(int x) {
    for(int i = x; i <= n; i ++) {
        for(int j = 0; j < vs[i].size(); j ++) {
            if(vis[i]) break;
            if(!vis[vs[i][j]]){
                vis[i] = vis[vs[i][j]] = 1;
                tmp++;
                if(tmp > ans) ans = tmp;
                dfs(x+1);
                tmp--;
                vis[i] = vis[vs[i][j]] = 0;
            }
        }
    }
}
int main() {
    cin >> m >> n;
    while (scanf("%d %d", &l, &r) != EOF) {
        if(l == -1 && r == -1) break;
        vs[r].push_back(l);
    }
    dfs(m+1);
    printf("%d\n", ans);
    return 0;
}
*/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 110;
int edge[N][N], vis[N], match[N];
int n, m;

bool dfs(int v) {
    for(int i = 1; i <= m; i ++) {
        if(edge[i][v] && !vis[i]) {
            vis[i] = 1;
            if(match[i] == -1 || dfs(match[i])) {
                match[i] = v;
                return true;
            }
        }
    }
    return false;
}
int max_match() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int i = m+1; i <= n; i ++) {
        if(match[i] < 0) {
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) res++;
        }
    }
    return res;
}
int main() {
    cin>>m>>n;
    memset(edge, 0, sizeof(edge));
    int u, v;
    while(cin >> u >> v) {
        if(u==-1 && v == -1)break;
        edge[u][v] = 1;
    }
    printf("%d\n",max_match());
    return 0;
}
