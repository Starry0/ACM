#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
vector<int> vs[N];
bool vis[N], flag;
int root;
void dfs(int x, int f, int de) {
    vis[x] = 1;
    if(vs[x].size() != 2) return;
    for(int i = 0; i < vs[x].size(); i ++) {
        int v = vs[x][i];
        if(!vis[v] && v != f) dfs(v, x,de+1);
        if(v == root && de != 1) {
            flag = true;
            return;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        vs[v].push_back(u);
        vs[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            flag = 0;
            root = i;
            dfs(i,-1,0);
            if(flag) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
