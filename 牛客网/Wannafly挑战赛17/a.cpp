#include <bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
int main() {
    int n, m;
    cin >> n >> m;
    int x = 1, y = 1;
    vis[x][y] = 1;
    while(m) {
        while(x+1 <= n && !vis[x+1][y] && m) {
            vis[++x][y] = 1;
            m--;
        }
        while(y+1 <= n && !vis[x][y+1] && m) {
            vis[x][++y] = 1;
            m--;
        }
        while(x-1 >= 1 && !vis[x-1][y] && m) {
            vis[--x][y] = 1;
            m--;
        }
        while(y-1 >=1 && !vis[x][y-1] && m) {
            vis[x][--y] = 1;
            m--;
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}
