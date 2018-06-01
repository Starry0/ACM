#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
char str[N][N];
int h, w;
bool ok(int x, int y) {
    if(str[x+1][y]=='#'||str[x-1][y]=='#'||str[x][y+1]=='#'||str[x][y-1]=='#') return 1;
    else return 0;
}
int main() {
    cin >> h >> w;
    for(int i = 1; i <= h; i ++) cin >> str[i]+1;
    for(int i = 1; i <= h; i ++) {
        for(int j = 1; j <= w; j ++) {
            if(str[i][j] == '#' && !ok(i,j))
                return 0*printf("No\n");
        }
    }
    printf("Yes\n");
    return 0;
}
