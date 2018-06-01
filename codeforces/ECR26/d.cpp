#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
struct Nod {
    ll a;
    int x,y;
    Nod(){
        a = x = y = 0;
    }
}nod[220];
void fun(Nod *p) {
    ll x = p->a;
    while(x%2 == 0){
        p->x++;
        x/=2;
    }
    x = p->a;
    while(x%5 == 0){
        p->y++;
        x/=5;
    }
}
int dp[210][18*210];
bool vis[220];
int main() {
    int n, k,MAXY=0;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
        cin >> nod[i].a, fun(&nod[i]),MAXY += nod[i].y;
    memset(dp, -1, sizeof(dp));
    // for(int i = 1; i <= n; i ++)printf("%d %d\n",nod[i].x,nod[i].y);
    // printf("%d\n",MAXY);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = k; j >= 1; j --) {
            for(int l = MAXY; l >= 0; l --) {
                if(l-nod[i].y < 0) continue;
                if(dp[j-1][l-nod[i].y] == -1) continue;
                dp[j][l] = max(dp[j][l], dp[j-1][l-nod[i].y]+nod[i].x);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= MAXY; i ++) {
        ans = max(ans, min(i,dp[k][i]));
    }
    printf("%d\n",ans);
    return 0;
}
