/*
这个代码有误，优先队列的就没事。
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
double G[N][N], vis[N], d[N];
int x[N], y[N], n, k = 1;
double dis(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}
void dijkstra() {
    for(int i = 1; i <= n; i ++) vis[i] = 0, d[i] = G[i][1];
    d[1] = 0;
    while(true) {
        int v = -1;
        for(int i = 1; i <= n; i ++) {
            if(!vis[i] && (v == -1 || d[v] > d[i])) v = i;
        }
        if(v == -1) break;
        vis[v] = 1;
        for(int i = 1; i <= n; i ++) {
            d[i] = max(d[i], G[i][v]);
        }
    }
}
int main() {
    while(scanf("%d",&n)&&n) {
        for(int i = 1; i < N; i ++) {
            for(int j = 1; j < N; j ++) {
                G[i][j] = (i==j ? 0: INF);
            }
        }
        for(int i = 1; i <= n; i ++) scanf("%d%d",&x[i], &y[i]);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(i > j) {
                    G[i][j] = G[j][i] = dis(i, j);
                }
            }
        }
        // for(int i = 1; i <= n; i ++) {
        //     for(int j = 1; j <= n; j ++) {
        //         printf("%.3f ",G[i][j]);
        //     }
        //     printf("\n");
        // }
        dijkstra();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",k++,d[2]);
    }
    return 0;
}
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
int x[N], y[N], n;
struct Nod {
    int to;
    double w;
};
vector<Nod> G[N];
double d[N];
typedef pair<double, int > P;
double dis(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double dij() {
    priority_queue<P, vector<P>, greater<P> > que;
    for(int i = 1; i <= n; i ++) d[i] = INF;
    d[1] = 0;
    que.push(P(0,1));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i ++) {
            Nod e = G[v][i];
            if(d[e.to] > max(d[v],e.w)) {
                d[e.to] = max(d[v],e.w);
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return d[2];
}
int main() {
    int k = 1;
    while(scanf("%d", &n)&&n) {
        for(int i = 1; i <= n; i ++) {
            scanf("%d %d",&x[i], &y[i]);
            G[i].clear();
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = i+1; j <= n; j ++) {
                double d = dis(i,j);
                G[i].push_back((Nod){j,d});
                G[j].push_back((Nod){i,d});
            }
        }
        printf("Scenario #%d\n",k++);
        printf("Frog Distance = %.3f\n\n",dij());
    }
    return 0;
}
