#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 220;
typedef pair<int,int> P;
vector<P> vs[N];
int ans = 0, n, m, d[N];

int bfs(int s) {
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    d[s] = 0;
    while(que.size()) {
        P p = que.top(); que.pop();
        if(p.second == n) return p.first;
        for(auto road : vs[p.second]) {
            if(d[road.first] > max(p.first, road.second)) {
                d[road.first] = max(p.first, road.second);
                que.push(P(d[road.first], road.first));
            }
        }
    }
    return INF;
}
int main() {
    while(cin >> n >> m) {
        for(int i = 0; i <= n; i ++) d[i] = INF;
        for(int i = 1; i <= m; i ++) {
            int x, y, z;
            cin >> x >> y >> z;
            vs[x].push_back(P(y,z));
        }
        printf("%d\n",bfs(1));
        for(int i = 0; i < N; i ++) vs[i].clear();
    }
    return 0;
}
