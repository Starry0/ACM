#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5+10;
vector<int> vs[N];
int n, x, y, u, v, s, t, flag1;
void dfs(int v, int fa, int flag) {
    u++;
    if(flag) {
        if(v == x) flag1 = 1;
    } else {
        if(v == y) flag1 = 1;
    }
    for(int i = 0; i < vs[v].size(); i ++) {
        if(vs[v][i] != fa) {
            dfs(vs[v][i], v, flag);
        }
    }
}
int main() {
    cin >> n >> x >> y;
    for(int i = 1; i < n; i ++) {
        scanf("%d%d",&u, &v);
        vs[u].push_back(v);
        vs[v].push_back(u);
    }
    for(int i = 0; i < vs[x].size(); i ++) {
        u = flag1 = 0;
        dfs(vs[x][i], x, 0);
        if(flag1) {
            s = n - u;
            break;
        }
    }
    for(int i = 0; i < vs[y].size(); i ++) {
        u = flag1 = 0;
        dfs(vs[y][i], y, 1);
        if(flag1) {
            t = n - u;
            break;
        }
    }
    ll ans = 1LL*n*(n-1);
    ans -= 1LL*s*t;
    cout << ans << endl;
    return 0;
}
