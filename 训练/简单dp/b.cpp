#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 5e5+10;
struct Nod{
    int x, y;
}nod[N];
bool cmp(Nod a, Nod b) {
    return a.x < b.x;
}
int dp[N];
int main(){
    int n,k = 1;
    while(scanf("%d",&n)!=EOF) {
        for(int i = 0; i < n; i ++) {
            scanf("%d%d",&nod[i].x,&nod[i].y);
            dp[i] = INF;
        }
        sort(nod,nod+n,cmp);
        for(int i = 0; i < n; i ++) {
            *lower_bound(dp,dp+n,nod[i].y) = nod[i].y;
        }
        int ans = lower_bound(dp,dp+n,INF) - dp;
        printf("Case %d:\n",k++);
        if(ans == 1)printf("My king, at most 1 road can be built.\n\n");
        else printf("My king, at most %d roads can be built.\n\n",ans);
    }
    return 0;
}
