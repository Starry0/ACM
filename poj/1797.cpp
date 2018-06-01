/*边很多，不能用优先队列
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
struct Nod {
    int to,w;
};
vector<Nod> G[N];
typedef pair<int,int> P;
int d[N], t, n, m;
int dij() {
    for(int i = 1; i <= n; i ++) d[i] = -1;
    d[1] = INF;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0,1));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i ++) {
            Nod e = G[v][i];
            if(d[e.to] < min(d[v], e.w)){
                d[e.to] = min(d[v], e.w);
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d[n];
}
int main() {
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        scanf("%d%d",&n,&m);
        for(int j = 1; j <= n; j ++) G[i].clear();
        for(int j = 1; j <= m; j ++) {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back((Nod){v,w});
            G[v].push_back((Nod){u,w});
        }
        printf("Scenario #%d:\n%d\n\n",i,dij());
    }
    return 0;
}
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = 1010;
int n, m, G[N][N], dis[N];
bool vis[N];
void dij(int s) {
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    int pos = s, MAX = -1;
    for(int i = 1; i <= n; i ++) dis[i] = G[s][i];
    for(int i = 1; i < n; i ++) {
        MAX = -1;
        for(int j = 1; j <= n; j ++) {
            if(MAX < dis[j] && !vis[j]) {
                MAX = dis[j];
                pos = j;
            }
        }
        vis[pos] = true;
        for(int j = 1; j <= n; j ++) {
            if(!vis[j] && G[j][pos] != -1) {
                if(dis[j] == -1) dis[j] = min(dis[pos], G[pos][j]);
                else dis[j] = max(dis[j], min(dis[pos], G[pos][j]));
            }
        }
    }
}
int main() {
    int t, k = 1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++)
            G[i][j] = -1;
        }
        for(int i = 1; i <= m; i ++) {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v] = max(G[u][v], w);
            G[v][u] = G[u][v];
        }
        dij(1);
        printf("Scenario #%d:\n%d\n\n",k++,dis[n]);
    }
    return 0;
}
