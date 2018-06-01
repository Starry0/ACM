#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5+10;
int fa[maxn], sum[maxn];

int find(int x){
    if(fa[x] == x)return x;
    int t = fa[x];
    fa[x] = find(fa[x]);
    sum[x] += sum[t];
    return fa[x];
}
void uni(int x, int y, int a, int b, int c){
    if(x > y){
        fa[y] = x;
        sum[y] = sum[a] - sum[b] - c;
    }else{
        fa[x] = y;
        sum[x] = sum[b] - sum[a] + c;
    }
}
int main(){
    int n, m;
    while(~scanf("%d%d",&n,&m)){
        for(int i = 0; i <= 200001; i++){
            fa[i] = i;
            sum[i] = 0;
        }
        int a, b, c, ans = 0;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            b++;
            int x = find(a);
            int y = find(b);
            if(x == y && sum[a] != sum[b] + c) ans++;
            else if(x != y) uni(x, y, a, b, c);
        }
        printf("%d\n",ans);
    }
    return 0;
}
