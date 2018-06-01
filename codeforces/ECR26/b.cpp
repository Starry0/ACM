#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define N 110
#define M 110
using namespace std;
char str[N][N];
int main() {
    int n, m, B = 0, R = 0, G = 0;
    int xb = N, yb = N, xxb = -1, yyb = -1;
    int xr = N, yr = N, xxr = -1, yyr = -1;
    int xg = N, yg = N, xxg = -1, yyg = -1;
    cin>>n>>m;
    for(int i = 1; i <= n; i ++) cin>>str[i]+1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(str[i][j] == 'B') {
                B++;
                xb = min(j, xb);
                yb = min(i, yb);
                xxb = max(xxb, j);
                yyb = max(yyb, i);
            }
            else if(str[i][j] == 'R') {
                R++;
                xr = min(j, xr);
                yr = min(i, yr);
                xxr = max(xxr, j);
                yyr = max(yyr, i);
            } else if(str[i][j] == 'G') {
                G++;
                xg = min(j, xg);
                yg = min(i, yg);
                xxg = max(xxg, j);
                yyg = max(yyg, i);
            }
        }
    }
    // printf("%c\n",str[1][3]);
    if(B != 0 && B == R && R == G) {
        if((yyb-yb+1)*(xxb-xb+1) == B && (yyr-yr+1)*(xxr-xr+1) == R && (yyg-yg+1)*(xxg-xg+1)==G) {
            printf("YES\n");
        } else printf("NO\n");
    } else printf("NO\n");
    return 0;
}
