/*#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int MAX = 1010;
struct Nod {
    int to, cost;
};
typedef pair<int,int> P;
int n,p,k;
vector<Nod> G[MAX];
int d[MAX];
int dij(int s, int x) {
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d,0x3f,sizeof(d));
    d[s] = 0;
    que.push(P(0,s));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i ++) {
            Nod e = G[v][i];
            int dd = d[v] + (e.cost > x ? 1 : 0);
            if(d[e.to] > dd) {
                d[e.to] = dd;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return d[n-1];
}
int main() {
    //ios::sync_with_stdio(false);
    while(cin>>n>>p>>k) {
        for(int i = 1; i <= p; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;--v;
            G[u].push_back((Nod){v,w});
            G[v].push_back((Nod){u,w});
        }
        int l = 0, r = 1000010, cnt = -1;
        while(l <= r) {
            int m = (l+r) >> 1;
            int ans = dij(0,m);
            // printf("%d  %d \n",m,ans);
            if(ans <= k){
                cnt = m;r = m-1;
            }else l = m+1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
*/

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <string.h>
// #include <functional>
// using namespace std;
//
// #define MAX_V 1000 + 16
// #define MAX_L 1000000
//
// // 从顶点from指向顶点to的权值为cost的边
// struct edge
// {
// 	int to, cost;
// 	edge(){}
// 	edge(int to, int cost) : to(to), cost(cost){}
// };
//
// // first 最短路径，second顶点编号
// typedef pair<int, int> P;
//
// // 边
// vector<edge> G[MAX_V];
//
// // 最短距离
// int d[MAX_V];
// // V是顶点数，E是边数
// int V, E;
//
// // 求解从顶点s出发到所有点的最短距离
// // x表示x单位之内免费
// // 返回需要的电线数量
// int dijkstra_ex(int s, int x)
// {
// 	priority_queue<P, vector<P>, greater<P> > que;
// 	memset(d, 0x3f, V * sizeof(int));
// 	d[s] = 0;
// 	que.push(P(0, s));
//
// 	while (!que.empty())
// 	{
// 		P p = que.top(); que.pop();
// 		int v = p.second;
// 		if (d[v] < p.first) continue;
// 		for (int i = 0; i < G[v].size(); ++i)
// 		{
// 			edge e = G[v][i];
// 			int new_d = d[v] + (e.cost >= x ? 1 : 0);
// 			if (d[e.to] > new_d)
// 			{
// 				d[e.to] = new_d;
// 				que.push(P(d[e.to], e.to));
// 			}
// 		}
// 	}
// 	return d[V - 1];
// }
//
// ///////////////////////////SubMain//////////////////////////////////
// int main(int argc, char *argv[])
// {
// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
// #endif
// 	int K;
// 	cin >> V >> E >> K;
// 	for (int i = 0; i < E; ++i)
// 	{
// 		int from, to, cost;
// 		cin >> from >> to >> cost;
// 		--from;
// 		--to;
// 		G[from].push_back(edge(to, cost));
// 		G[to].push_back(edge(from, cost));
// 	}
// 	int lb = 0, ub = MAX_L + 2;
// 	while (ub - lb > 1)
// 	{
// 		int mid = (ub + lb) >> 1;
// 		if (dijkstra_ex(0, mid) > K)
// 		{// mid 太取小了
// 			lb = mid;
// 		}
// 		else
// 		{
// 			ub = mid;
// 		}
// 	}
// 	cout << (lb > MAX_L ? -1 : lb) << endl;
// #ifndef ONLINE_JUDGE
// 	fclose(stdin);
// 	fclose(stdout);
// 	system("out.txt");
// #endif
// 	return 0;
// }

/*
分层图
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int n, p, k, vis[1010][1010], d[1010][1010];
typedef pair<int,int> P;
struct Nod {
    int v, c, w;
    bool operator < (const Nod &a) const {
        return w > a.w;
    }
};
vector<P> G[1010];
void spfa(int s) {
    memset(d,-1,sizeof(d));memset(vis,0,sizeof(vis));
    d[s][0] = 0;
    priority_queue<Nod> que;
    que.push((Nod){s,0,0});
    while(!que.empty()) {
        int u = que.top().v, c = que.top().c; que.pop();
        if(vis[u][c])continue;
        vis[u][c] = 1;
        for(int i = 0; i < G[u].size(); i ++) {
            int v = G[u][i].first, w = G[u][i].second;
            if(!vis[v][c] && (d[v][c] == -1 || d[v][c] > max(d[u][c],w))) {
                d[v][c] = max(d[u][c], w);
                que.push((Nod){v,c,d[v][c]});
            }
            if(c < k) {
                if(!vis[v][c+1] && (d[v][c+1] == -1 || d[v][c+1] > d[u][c])) {
                    d[v][c+1] = d[u][c];
                    que.push((Nod){v,c+1,d[v][c+1]});
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>p>>k;
    int s = 1, t = n;
    for(int i = 1; i <= p; i ++) {
        int u, v, w;
        cin>>u>>v>>w;
        G[u].push_back(P(v,w));
        G[v].push_back(P(u,w));
    }
    spfa(s);
    int ans = 10000010;
    for(int i = 0; i <= k; i ++) ans = min(ans,d[t][i]);
    printf("%d\n",ans);
    return 0;
}
