#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 550;
int n, m, c1, c2, u, v, w;
int g[N][N], a[N], d[N], c[N], b[N], vis[N];
void dij(int s) {
    int pos = s;
    c[pos] = a[pos];
    d[pos] = 0;
    b[pos] = 1;
    while(true){
        int mins = INF;
        for(int i = 0; i < n; i ++) {
            if(!vis[i] && d[i] < mins) {
                pos = i;
                mins = d[i];
            }
        }
        if(mins == INF || pos == c2) break;
        vis[pos] = true;
        for(int i = 0; i < n; i ++) {
            if(!vis[i] && d[i] > d[pos] + g[pos][i]) {
                d[i] = d[pos] + g[pos][i];
                c[i] = c[pos] + a[i];
                b[i] = b[pos];
            } else if(!vis[i] && d[i] == d[pos] + g[pos][i]) {
                b[i] += b[pos];
                if(c[i] < c[pos] + a[i]) {
                    c[i] = c[pos] + a[i];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> c1 >> c2;
    memset(g, INF, sizeof(g));
    memset(d, INF, sizeof(d));
    for(int i = 0; i < n; i ++) g[i][i] = 0;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) {
        cin >> u >> v >> w;
        if(g[u][v] > w) {
            g[u][v] = g[v][u] = w;
        }
    }
    dij(c1);
    cout << b[c2] << ' ' << c[c2] << endl;
    // for(int i = 0; i < n; i ++) printf("%d%c",b[i]," \n"[i==n-1]);
    // for(int i = 0; i < n; i ++) printf("%d%c",c[i]," \n"[i==n-1]);
    // for(int i = 0; i < n; i ++) printf("%d%c",d[i]," \n"[i==n-1]);
    return 0;
}
