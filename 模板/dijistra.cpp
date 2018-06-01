/*
*最短路
*/

void dijistra(int x){
    int pos = x;
    for(int i = 1; i <= n; i ++){
        dist[i] = g[i][pos];
    }
    vis[pos] = true;
    for(int i = 1; i <= n; i ++){
        int mins = INF;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && dist[j] < mins){
                pos = j;
                mins = dist[j];
            }
        }
        vis[pos] = true;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && dist[j] > dist[pos] + g[pos][j]){
                dist[j] = dist[pos] + g[pos][j];
            }
        }
    }
}



/*
*优化的dijistra算法
*/

struct edge{
    int to, cost;
};
vector<edge> g[N];
typedef pair<int,int> P; // first是最短距离，second是定点的编号
void dijistra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    d[a] = 0;
    que.push(P(0,s));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
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