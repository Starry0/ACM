#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
ll f[N], x;
bool vis[N];
map<ll,int> mp;
void dfs(int id) {
    if(id < 2) return ;
    if(!vis[id-1] && !vis[id-2]) {
        vis[id-1] = vis[id-2] = true;
        vis[id] = false;
        dfs(id-2);
    }
}
int main() {
    f[0] = 1;f[1] = 2;//43 1134903170
    mp[1] = 0; mp[2] = 1;
    for(int i = 2; i <55; i ++) {
        f[i] = f[i-1] + f[i-2];
        mp[f[i]] = i;
    }
    int t;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof(vis));
        cin >> x;
        while(x) {
            if(mp[x] || x == 1) {
                vis[mp[x]] = 1;
                x = 0;
                break;
            }
            int id = upper_bound(f,f+50,x/2)-f;
            vis[id] = 1;
            x -= f[id];
        }
        for(int i = 2; i < N; i ++) {
            if(vis[i]) dfs(i);
        }
        for(int i = 0; i < 50; i ++) {
            if(vis[i]) {
                x += (1LL<<i);
            }
        }
        cout << x << endl;
    }
    return 0;
}
