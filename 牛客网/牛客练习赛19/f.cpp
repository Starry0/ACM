#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 100010;
ll tree[MAX<<2], add[MAX<<2];
int n, m, a[MAX];
void PushUp(int rt){
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void PushDown(int rt, int m){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        tree[rt<<1] += add[rt]*(m-(m>>1));
        tree[rt<<1|1] += add[rt]*(m>>1);
        add[rt] = 0;
    }
}
void build(int l, int r, int rt){
    add[rt] = 0;
    if(l == r){
        scanf("%lld",&tree[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int LL, int RR, int num, int l, int r, int rt){
    if(LL <= l && r <= RR){
        add[rt] += num;
        tree[rt] += (ll)num * (r-l+1);
        return;
    }
    PushDown(rt,r-l+1);
    int m = (l+r)>>1;
    if(LL <= m)update(LL,RR,num,lson);
    if(m < RR) update(LL,RR,num,rson);
    PushUp(rt);
}
ll query(int LL, int RR, int l, int r, int rt){
    if(LL <= l && r <= RR){
        return tree[rt];
    }
    PushDown(rt,r-l+1);
    int m = (l+r)>>1;
    ll res = 0;
    if(LL <= m) res += query(LL,RR,lson);
    if(m < RR) res += query(LL,RR,rson);
    return res;
}
void update1(int LL, int RR, int val, int l, int r, int rt){
    if(LL <= l && r <= RR){
        tree[rt] = val;
        return;
    }
    PushDown(rt,r-l+1);
    int m = (l+r)>>1;
    if(LL <= m) update1(LL,RR,val,lson);
    if(m < RR) update1(LL,RR,val,rson);
}
int main() {
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while(m--) {
        int op, x, y;
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &x, &y);
            update1(x, x, y, 1, n, 1);
        } else if(op == 2) {
            scanf("%d", &y);
            update(1, n, y, 1, n, 1);
        } else if(op == 3) {
            scanf("%d", &x);
            printf("%lld\n",query(x, x, 1, n, 1));
        }
    }
    return 0;
}
