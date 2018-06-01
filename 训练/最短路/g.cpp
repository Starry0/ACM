#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int N = 220;
const int INF = 1e7;
int d[N], n, a, b;

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


int main(){
    while(~scanf("%d",&n)&&n){
        for(int i = 0; i < N; i ++){
            d[i] = INF;
            g[i].clear();
        }
        scanf("%d %d",&a,&b);
        for(int i = 1; i <= n; i ++){
            int tmp;
            edge e;
            scanf("%d",&tmp);
            if(i-tmp > 0){
                e.to = i-tmp;
                e.cost = 1;
                g[i].push_back(e);
            }
            if(i+tmp <= n){
                e.to = i + tmp;
                e.cost = 1;
                g[i].push_back(e);
            }
        }
        dijistra(a);
        printf("%d\n",(d[b]==INF)?-1:d[b]);
    }
    return 0;
}
