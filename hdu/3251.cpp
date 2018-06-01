#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int M = 210010;
struct Nod {
    int to, cap, next, index;
}edge[M];
int T, n, m, f, s, t;
int head[M], level[M], vis[M], iter[M], sum, num;
void init() {
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    num = 0;
    sum = 0;
}
void add_edge(int u, int v, int cap, int index) {
    edge[num].to = v; edge[num].cap = cap; edge[num].next = head[u]; edge[num].index = index; head[u] = num++;
    edge[num].to = u; edge[num].cap = 0; edge[num].next = head[v]; edge[num].index = -1; head[v] = num++;
}
bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(int i = head[v]; i != -1; i = edge[i].next) {
            int u = edge[i].to;
            if(level[u] < 0 && edge[i].cap) {
                level[u] = level[v] + 1;
                que.push(u);
            }
        }
    }
    return level[t] != -1;
}
int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i = iter[v]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if(level[u] > level[v] && edge[i].cap > 0) {
            int d = dfs(u, t, min(f, edge[i].cap));
            if(d > 0) {
                edge[i].cap -= d;
                edge[i^1].cap += d;
                return d;
            }
        }
    }
    level[v] = -1;
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while(bfs(s, t)) {
        for(int i = 0; i <= t + 10; i ++) iter[i] = head[i];
        int f = 0;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
}
void dfs(int u, int fa) {
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(!vis[v] && edge[i].cap) {
            vis[v] = true;
            dfs(v, u);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    // cin >> T;
    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        // cin >> n >> m >> f;
        scanf("%d %d %d", &n, &m, &f);
        init();
        add_edge(s, 1, INF, -1);
        s = 0, t = n + 1;
        for(int i = 1; i <= m; i ++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w, i);
        }
        for(int i = 1; i <= f; i ++) {
            int u, w;
            scanf("%d %d", &u, &w);
            add_edge(u, t, w, -1);
            sum += w;
        }
        int ans = max_flow(s, t);
        ans = sum - ans;
        printf("Case %d: %d\n",cas++, ans);
        vis[1] = true;
        dfs(1, -1);
        queue<int> que;
        for(int i = 0; i < num; i += 2) {//0正1负
            if(vis[edge[i^1].to] && !vis[edge[i].to] && edge[i].index != -1) que.push(edge[i].index);
        }
        printf("%d",(int)que.size());
        while(!que.empty()) {
            printf(" %d",que.front());
            que.pop();
        }
        printf("\n");
    }
    return 0;
}
