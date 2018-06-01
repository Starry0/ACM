#include <iostream>
#include <cstdio>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = 2e5+10;
using namespace std;
int dit[maxn<<2], x[maxn];
void build(int l, int r, int rt){
    dit[rt] = -1;
    if(l == r)return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
int main()
{
    int n;
    while(~scanf("%d",&n)){
        build(1, n, 1);
        for(int i = 1; i <= n; i++){
            scanf("%d",&x[i]);

        }
    }
    return 0;
}
