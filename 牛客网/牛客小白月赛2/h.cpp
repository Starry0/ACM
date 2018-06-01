#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 100010;
ll d[N];
struct edge{
    ll to, cost;
};

vector<edge> g[N];
typedef pair<ll,ll> P;
void dijistra(ll s){
    priority_queue<P,vector<P>,greater<P> > que;
    d[s] = 0;
    que.push(P(0,s));
    while(!que.empty()){
        P p = que.top();que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < g[v].size(); i ++){
            edge e = g[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main() {
    ll n, p, k;
    cin >> n >> p >> k;
    for(int i = 0; i <= n; i ++) d[i] = 2e10;
    for(int i = 0; i < n-1; i ++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edge e;
        e.to = v;
        e.cost = w;
        g[u].push_back(e);
        edge ee;
        ee.to = u;
        ee.cost = w;
        g[v].push_back(ee);
    }
    dijistra(p);
    sort(d+1,d+1+n);
    cout << d[k+1] << endl;
    return 0;
}
