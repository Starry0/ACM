#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e3;
int fa[maxn*2+10];
bool mark;
int find(int x){
    if(fa[x] == x)return x;
    else return fa[x] = find(fa[x]);
}
void uni(int x, int y){
    int xx, yy;
    xx = find(x);
    yy = find(y-maxn);
    if(xx == yy){
        mark = false;
        return;
    }
    yy = find(y);
    if(xx != yy) fa[xx] = fa[yy];
}
int main(){
    int t, n, m, x, y, k = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= maxn+n; i++)fa[i] = i;
        mark = true;
        for(int i = 1; i <= m; i ++){
            scanf("%d%d",&x,&y);
            if(mark){
                uni(x, y+maxn);
                uni(y, x+maxn);
            }
        }
        printf("Scenario #%d:\n", k++);
        if(mark) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
