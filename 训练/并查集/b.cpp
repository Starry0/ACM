#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 3e4+10;
int fa[maxn], rank[maxn];
int n, m;
int find(int x){
    if(x == fa[x])return x;
    else return fa[x] = find(fa[x]);
}
void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x < y){
        fa[y] = x;
    }else{
        fa[x] = y;
    }
}
int main(){
    while(~scanf("%d",&n)&&n){
        scanf("%d",&m);
        int ans = 0;
        for(int i = 1; i < n; i ++){
            fa[i] = i;
            rank[i] = 0;
        }
        for(int i = 1; i <= m; i ++){
            int a, b, c;
            scanf("%d%d",&a,&b);
            for(int i = 1; i < a; i ++){
                scanf("%d",&c);
                uni(b, c);
            }
        }
        for(int i = 0; i < n; i ++){
            if(find(i) == 0) ans ++;
        }
        printf("%d\n",ans);
    }
    return 0;
}