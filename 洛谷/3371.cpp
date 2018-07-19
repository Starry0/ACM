#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to, cost;
};
vector<edge> g[N];
typedef pair<int,int> P; 
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