#include <iostream>
#include <cstdio>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;
const int maxn = 2e5+10;
int n, h, w;
int MAX[maxn<<2];
void PushUP(int rt){
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}

void build(int l, int r, int rt){
    MAX[rt] = w;
    if(l == r)return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
int query(int q, int l, int r, int rt){
    if(l == r){
        MAX[rt] -= q;
        return l;
    }
    int m = (l + r) >> 1;
    int ret = (MAX[rt<<1] >= q)?query(q, lson):query(q, rson);
    PushUP(rt);
    return ret;
}

int main()
{
    while(~scanf("%d%d%d",&h,&w,&n)){
        if(h > n) h = n;
        build(1, h, 1);
        while(n--){
            int x;
            scanf("%d",&x);
            if(MAX[1] < x) printf("-1\n");
            else printf("%d\n",query(x, 1, h, 1));
        }
    }
    return 0;
}
