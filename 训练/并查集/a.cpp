#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e3+10;
int fa[maxn];
int n, m;
int find(int x){
    if(fa[x] == x)return x;
    else return fa[x] = find(fa[x]);
}
void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(x < y){
        fa[x] = y;
    }else{
        fa[y] = x;
    }
}
int main(){
    int a, b;
    while(~scanf("%d",&n)){
        if(n == 0)break;
        scanf("%d",&m);
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            fa[i] = i;
        }
        for(int i = 1; i <= m; i ++){
            scanf("%d%d",&a,&b);
            uni(a,b);
        }
        for(int i = 1; i <= n; i ++){
            if(fa[i] == i) ans++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
