#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
typedef pair<ll,int> P;
vector<P> vs[N];
int n, m, u, v;
ll w, x, d[N];
void dij(int s) {
    for(int i = 1; i <= n; i ++) {
        d[i] = 1LL<<60;
    }
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> >que;
    que.push(P(0,s));
    while(que.size()) {
        P p = que.top();
        que.pop();
        int u = p.second;
        if(d[u] < p.first) continue;
        for(int i = 0; i < vs[u].size(); i ++) {
            P x = vs[u][i];
            if(d[x.second] > d[u] + x.first) {
                d[x.second] = d[u] + x.first;
                que.push(P(d[x.second],x.second));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> u >> v >> w;
        vs[u].push_back(P(2*w,v));
        vs[v].push_back(P(2*w,u));
    }
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        vs[n+1].push_back(P(x,i));
    }
    dij(n+1);
    for(int i = 1; i <= n; i ++) {
        printf("%lld%c",d[i]," \n"[i==n]);
    }
    return 0;
}


//上面的卡时间
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// typedef pair<ll,ll> P;
// vector<P> vs[N];
// ll d[N], n, m, u, v, w;
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     for(int i = 1; i <= m; i ++) {
//         cin >> u >> v >> w;
//         vs[u].push_back(P(v,2*w));
//         vs[v].push_back(P(u,2*w));
//     }
//     priority_queue<P> que;
//     for(int i = 1; i <= n; i ++) {
//         cin >> d[i];
//         que.push(P(-d[i],i));
//     }
//     while(que.size()) {
//         ll u = que.top().second, w = -que.top().first;
//         que.pop();
//         if(w != d[u]) continue;
//         for(auto X : vs[u]) {
//             ll v = X.first, w = X.second;
//             if(d[v] > d[u] + w) {
//                 d[v] = d[u] + w;
//                 que.push(P(-d[v],v));
//             }
//         }
//     }
//     for(int i = 1; i <= n; i ++) {
//         printf("%lld%c",d[i]," \n"[i==n]);
//     }
//     return 0;
// }
