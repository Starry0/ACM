/*
Ford-Fullkerson
*/

/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 20;
int t, n, m, u, v, w;
struct Nod{
    int to, cap, rev;
};
vector<Nod> vs[N];
bool vis[N];
void add_edge(int from, int to, int cap) {
    vs[from].push_back((Nod){to, cap, (int)vs[to].size()});
    vs[to].push_back((Nod){from, 0, (int)vs[from].size() - 1});
}
int dfs(int v, int t, int f) {
    if(v == t) return f;
    vis[v] = true;
    for(int i = 0; i < vs[v].size(); i ++) {
        Nod &e = vs[v][i];
        if(!vis[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0) {
                e.cap -= d;
                vs[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
        memset(vis, 0, sizeof(vis));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}

int main() {
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca ++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, 0);
        }
        printf("Case %d: %d\n",ca, max_flow(1, n));
        for(int i = 1; i <= n; i ++) vs[i].clear();
    }
    return 0;
}
*/
/*
Edmond—Karp 算法
*/
/*#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 20;
int n, m, u, v, w, t;
int g[N][N], flow[N], pre[N];

int bfs(int s, int t) {
    queue<int> que;
    memset(pre, -1, sizeof(pre));
    pre[s] = 0;
    flow[s] = INF;
    que.push(s);
    while(que.size()) {
        int id = que.front();
        que.pop();
        if(id == t) break;
        for(int i = 1; i <= n; i ++) {
            if(i != s && g[id][i] > 0 && pre[i] == -1) {
                pre[i] = id;
                flow[i] = min(flow[id], g[id][i]);
                que.push(i);
            }
        }
    }
    if(pre[t] == -1) return -1;
    else return flow[t];
}

int max_flow(int s, int t) {
    int ans = 0;
    int sumflow = 0;
    while((ans = bfs(s, t)) != -1) {
        int k = t;
        while(k != s) {
            int last = pre[k];
            g[last][k] -= ans;
            g[k][last] += ans;
            k = last;
        }
        sumflow += ans;
    }
    return sumflow;
}

int main() {
    cin >> t;
    for(int ca = 1; ca <= t; ca ++) {
        cin >> n >> m;
        memset(g, 0, sizeof(g));
        memset(flow, 0, sizeof(flow));
        for(int i = 0; i < m; i ++) {
            cin >> u >> v >> w;
            if(u == v) continue;
            g[u][v] += w;
        }
        printf("Case %d: %d\n", ca, max_flow(1, n));
    }
    return 0;
}
*/
/*
Dinic算法
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 220;
int n, m, t, u, v, w;
int level[N], iter[N];
struct Nod{
    int to, cap, rev;
};
vector<Nod> vs[N];
void add_edge(int from, int to, int cap) {
    vs[from].push_back((Nod){to, cap, (int)vs[to].size()});
    vs[to].push_back((Nod){from, 0, (int)vs[from].size() - 1});
}
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(que.size()) {
        int v = que.front();
        que.pop();
        for(int i = 0; i < vs[v].size(); i ++) {
            Nod e = vs[v][i];
            if(e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i = iter[v]; i < vs[v].size(); i ++) {
        Nod &e = vs[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0) {
                e.cap -= d;
                vs[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while(true){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}
int main() {
    cin >>t;
    for(int ca = 1; ca <= t; ca ++) {
        cin >> n >> m;
        for(int i = 1; i <= m; i ++) {
            cin >> u >> v >> w;
            add_edge(u, v, w);
            add_edge(v, u, 0);
        }
        printf("Case %d: %d\n", ca, max_flow(1, n));
        for(int i = 1; i <= n; i ++) vs[i].clear();
    }
    return 0;
}
