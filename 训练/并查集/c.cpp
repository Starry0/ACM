#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e3+10;
int fa[maxn];
int find(int x){
    if(fa[x] == x)return x;
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
    int t, n, m;
    scanf("%d",&t);
    while(t--){
        int ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i ++) fa[i] = i;
        for(int i  = 0; i < m; i ++){
            int a, b;
            scanf("%d%d",&a,&b);
            uni(a, b);
        }
        for(int i = 1; i <= n; i ++){
            if(fa[i] == i) ans ++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
