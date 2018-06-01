#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 330;
char str[N][N];
typedef pair<int,int> P;
std::vector<P> v[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int sx, sy, tx, ty, n, m, q;
int d[N][N];
void bfs() {
    queue<P> que;
    memset(d, -1, sizeof(d));
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    while(que.size()) {
        P p = que.front(); que.pop();
        for(int i = 0; i < 4; i ++) {
            int nx = dx[i] + p.first, ny = dy[i] + p.second;
            if(0 <= nx && nx < n && 0 <= ny && ny < m && str[nx][ny] != '#') {
                if(d[nx][ny] == -1 || d[nx][ny] > d[p.first][p.second] + 1) {
                    que.push(P(nx,ny));
                    d[nx][ny] = d[p.first][p.second] + 1;
                }
            }
        }
        for(int i = 0; i < v[p.first][p.second].size(); i ++) {
            int nx = v[p.first][p.second][i].first;
            int ny = v[p.first][p.second][i].second;
            if(0 <= nx && nx < n && 0 <= ny && ny < m && str[nx][ny] != '#') {
                if(d[nx][ny] == -1 || d[nx][ny] > d[p.first][p.second] + 1) {
                    que.push(P(nx,ny));
                    d[nx][ny] = d[p.first][p.second] + 3;
                }
            }
        }
    }
}
void init() {
    memset(str,0,sizeof(str));
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            v[i][j].clear();
        }
    }
}
int main() {
    while(cin >> n >> m >> q) {
        for(int i = 0; i < n; i ++) cin >> str[i];
        for(int i = 1; i <= q; i ++) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            v[x1][y1].push_back(P(x2,y2));
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(str[i][j] == 'S') {
                    sx = i;sy = j;
                }else if(str[i][j] == 'T') {
                    tx = i; ty = j;
                }
            }
        }
        bfs();
        printf("%d\n",d[tx][ty]);
        init();
    }
    return 0;
}
