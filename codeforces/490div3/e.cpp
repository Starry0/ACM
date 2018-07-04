#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+10;
vector<int> vs[N];
int n, m, s, v, u, ans, a[N];
bool vis[N];
void dfs(int vv, int de) {
    a[de++] = vv;
    if(vv == s) {
        for(int i = 0; i < de; i ++) vis[a[i]] = true;
        return ;
    }
    for(int i = 0; i < vs[vv].size(); i ++) {
        dfs(vs[vv][i], de+1);
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < m; i ++) {
        scanf("%d%d", &v, &u);
        vs[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) {
        a[0] = i;
        dfs(i, 1);
    }
    for(int i = 1; i <= n; i ++) printf("%d %d\n",i,vis[i] );
    for(int i = 1; i <= n; i ++) if(!vis[i]) ans++;
    cout << ans << endl;
    return 0;
}
