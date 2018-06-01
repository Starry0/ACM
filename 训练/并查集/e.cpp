#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e4+10;
int fa[maxn*3],rank[maxn*3];
int find(int x){
    if(fa[x] == x)return x;
    else return fa[x] = find(fa[x]);
}
void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]){
        fa[x] = y;
    }else{
        fa[y] = x;
        if(rank[x] == rank[y])rank[x]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
int main(){
    int n, k, a, b, c;
    while(~scanf("%d%d",&n,&k)){
        int ans = 0;
        for(int i = 0; i <= n*3; i ++){
            fa[i] = i;
            rank[i] = 0;
        }
        for(int i = 1; i <= k; i ++){
            scanf("%d%d%d",&a,&b,&c);
            b--;c--;
            if(0 > b || b >= n || 0 > c || c >= n){
                ans++;
                continue;
            }
            if(a == 1){
                if(same(b, c + n) || same(b, c + 2*n)){
                    ans++;
                }else{
                    uni(b, c);
                    uni(b+n, c+n);
                    uni(b+2*n, b+2*n);
                }
            }else{
                if(same(b, c) || same(b, c+2*n)){
                    ans++;
                }else{
                    uni(b, c+n);
                    uni(b+n, c+2*n);
                    uni(b+2*n, c);
                }
            }
        }
        printf("%d\n",ans);
     }
     return 0;
}
