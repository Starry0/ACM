#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e3+10;
int n, m, x1, x2, y1, y2;
typedef pair<int, int> P;
string s[maxn];
int d[maxn][maxn];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(){
    x1--;x2--;y1--;y2--;
    for(int i = 0; i < n; i ++) cin >> s[i];
    memset(d, -1, sizeof(d));
    queue<P> que;
    que.push(P(x1,y1));
    d[x1][y1] = 0;
    while(que.size()){
        P p = que.front();que.pop();
        if(p.first == x2 && p.second == y2)break;
        for(int i = 0; i < 4; i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != '0' && d[nx][ny] == -1){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    printf("%d\n",d[x2][y2]);
    return;
}

int main(){
    while(cin>>n>>m>>x1>>y1>>x2>>y2)
        solve();
    return 0;
}