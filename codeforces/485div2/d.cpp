#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, m, k, s, u, v;
int a[N], vis[110], vis1[110];
vector<int> vs[N];
typedef pair<int,int> P;
int bfs(int x) {
    memset(vis, 0, sizeof(vis));
    memset(vis1, 0, sizeof(vis));
    int ans = 1, cnt = 0;
    queue<P> que;
    que.push(P(x,0));
    vis[x] = 1;
    vis1[a[x]] = 1;
    while(que.size()) {
        P p = que.front();
        que.pop();
        for(int i = 0; i < vs[p.first].size(); i ++) {
            int u = vs[p.first][i];
            if(!vis[u]) {
                que.push(P(u,p.second+1));
                if(!vis1[a[u]]) {
                    cnt += p.second+1;
                    ans++;
                    vis1[a[u]] = 1;
                    if(ans == s) return cnt;
                }
                vis[u] = 1;
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> s;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) {
        cin >> u >> v;
        vs[u].push_back(v);
        vs[v].push_back(u);
    }
    // cout << bfs(3) << endl;
    for(int i = 1; i <= n; i ++) {
        if(s == 1) printf("0 ");
        else printf("%d ",bfs(i));
    }printf("\n");
    return 0;
}
