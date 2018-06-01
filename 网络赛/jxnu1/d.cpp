#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
int n,m,W;
int w[1010], b[1010],fa[1010], dp[1010];
struct Nod{
    int w, b;
    Nod(){
        w = b = 0;
    }
}nod[1010];
int find(int x) {
    return fa[x] = (x==fa[x])?x:find(fa[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) fa[y] = x;
    else fa[x] = y;
}
int main() {
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m>>W) {
        for(int i = 1; i <= n; i ++) cin>>w[i],fa[i] = i;
        for(int i = 1; i <= n; i ++) cin>>b[i];
        for(int i = 1; i <= m; i ++) {
            int x, y;
            cin>>x>>y;
            unite(x,y);
        }
        for(int i = 1; i <= n; i ++) {
            int x = find(i);
            nod[x].w += w[i];
            nod[x].b += b[i];
        }
        for(int i = 1; i <= n; i ++) {
            if(nod[i].b != 0 && nod[i].w != 0) {
                for(int j = W; j >= nod[i].w; j --) {
                    dp[j] = max(dp[j],dp[j-nod[i].w]+nod[i].b);
                }
            }
        }
        printf("%d\n",dp[W]);
        for(int i = 1; i <= n; i ++){
            nod[i].b = nod[i].w = 0;
        }
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
