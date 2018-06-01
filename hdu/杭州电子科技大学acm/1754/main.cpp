#include <iostream>
#include <cstdio>
#define lson l, m, rt<<1
#define rson m+1,r, rt<<1|1

using namespace std;
const int maxn = 1e6+2;
int MAX[maxn<<2];
int max(int a, int b){
    return a>b?a:b;
}
void PushDP(int rt){
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}
void build(int l, int r, int rt){
    if(l == r){
        scanf("%d",&MAX[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushDP(rt);
}
void update(int x, int y, int l, int r, int rt){
    if ( l == r){
        MAX[rt] = y;
        return ;
    }
    int m = (l + r) >> 1;
    if(x <= m) update(x, y, lson);
    else update(x, y, rson);
    PushDP(rt);
}
int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return MAX[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if( m >= L) ret = max(ret, Query(L, R ,lson));
    if( m < R) ret = max(ret, Query(L, R, rson));
    return ret;
}
int main()
{
    int n, m, x, y, i;
    char c;
    while(cin>>n>>m){
        build(1, n, 1);
        for(i = 1; i <= m; i++){
            scanf(" %c%d%d",&c,&x,&y);
            //cin >> c >> x >> y;
            if(c == 'Q'){
                printf("%d\n",Query(x, y, 1, n, 1));
            }
            else{
                update(x, y, 1, n, 1);
            }
        }
    }
    return 0;
}
