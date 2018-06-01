#include <iostream>
#include <cstring>
#include <stdio.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 440;
int g[N][N], d[N], n, m, g1[N][N];
bool vis[N];
void dijistra(int x) {
    int pos = x;
    for(int i = 1; i <= n; i ++) {
        d[i] = g[i][pos];
    }
    vis[pos] = true;
    for(int i = 1; i <= n; i ++) {
        int mins = INF;
        for(int j = 1; j <= n; j ++) {
            if(!vis[j]&&d[j] < mins) {
                pos = j;
                mins = d[j];
            }
        }
        vis[pos] = true;
        for(int j = 1; j <= n; j ++) {
            if(!vis[j] && d[j] > d[pos] + g[pos][j]) {
                d[j] = d[pos] + g[pos][j];
            }
        }
    }
}
void dijistra1(int x) {
    memset(vis,0,sizeof(vis));
    int pos = x;
    for(int i = 1; i <= n; i ++) {
        d[i] = g1[i][pos];
    }
    vis[pos] = true;
    for(int i = 1; i <= n; i ++) {
        int mins = INF;
        for(int j = 1; j <= n; j ++) {
            if(!vis[j]&&d[j] < mins) {
                pos = j;
                mins = d[j];
            }
        }
        vis[pos] = true;
        for(int j = 1; j <= n; j ++) {
            if(!vis[j] && d[j] > d[pos] + g1[pos][j]) {
                d[j] = d[pos] + g1[pos][j];
            }
        }
    }
}
int main() {
    memset(g, INF, sizeof(g));
    std::cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y;
        std::cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            g1[i][j] = (g[i][j]==INF)?1:INF;
        }
    }
    dijistra(1);
    int ans1 = d[n];
    dijistra1(1);
    int ans2 = d[n];
    if(ans1 == INF || ans2 == INF) printf("-1\n");
    else printf("%d\n",max(ans1,ans2));
    return 0;
}
