/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100010;
typedef pair<ll,ll> P;
vector<P> vs[N];
bool vis[N];
ll t, n, m;
ll x[N], y[N];
bool ok(ll m) {
    memset(vis, 0, sizeof(vis));
    queue<int> que;
    for(int i = 1; i <= n; i ++) {
        y[i] = x[i];
        if(x[i] <= m) {
            vis[i] = true;
            que.push(i);
        }
    }
    while(que.size()) {
        int u = que.front();
        que.pop();
        vis[u] = true;
        for(int i = 0; i < vs[u].size(); i ++) {
            ll v = vs[u][i].first, w = vs[u][i].second;
            if(!vis[v]) {
                y[v] -= w;
                if(y[v] <= m) {
                    que.push(v);
                    vis[i] = true;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < m; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            vs[u].push_back(P(v,w));
            vs[v].push_back(P(u,w));
            x[u] += w;
            x[v] += w;
        }
        ll l = 0, r = *max_element(x,x+n);
        ll ans = r;
        while(l <= r) {
            ll m = (l+r) >> 1;
            if(ok(m)) {
                r = m-1;
                ans = min(ans,m);
            }
            else l = m+1;
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i ++) {
            vs[i].clear();
        }
        memset(x,0,sizeof(x));
    }
    return 0;
}
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
typedef pair<ll, ll> P;
vector<P> vs[N];
bool vis[N];
set<P> st;
ll a[N], n, m, t;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= m; i ++) {
            ll u, v, w;
            cin >> u >> v >> w;
            a[u] += w;
            a[v] += w;
            vs[u].push_back(P(v,w));
            vs[v].push_back(P(u,w));
        }
        for(int i = 1; i <= n; i ++) {
            st.insert(P(a[i], i));
        }
        ll ans = 0;
        for(int i = 1; i <= n; i ++) {
            ll u = st.begin()->second;
            st.erase(st.begin());
            ans = max(ans,a[u]);
            vis[u] = 1;
            for(int j = 0; j < vs[u].size(); j ++) {
                ll v = vs[u][j].first, w = vs[u][j].second;
                if(!vis[v]){
                    st.erase(P(a[v],v));
                    a[v] -= w;
                    st.insert(P(a[v],v));
                }
            }
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i ++) {
            vs[i].clear();
        }
        st.clear();
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
    }
    return 0;
}
