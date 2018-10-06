#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e4+10;
ll tree[N<<2], add[N<<2];
ll tree1[N<<2], mul[N<<2];
void PushUp(int rt){
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
    tree1[rt] = tree1[rt<<1]+tree1[rt<<1|1];
}
void PushDown(int rt, int m){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        tree[rt<<1] += add[rt]*(m-(m>>1));
        tree[rt<<1|1] += add[rt]*(m>>1);
        add[rt] = 0;
    }
    if(mul[rt]){
        mul[rt<<1] += mul[rt];
        mul[rt<<1|1] += mul[rt];
        tree1[rt<<1] += mul[rt]*(m-(m>>1));
        tree1[rt<<1|1] += mul[rt]*(m>>1);
        mul[rt] = 0;
    }
}
void build(int l, int r, int rt){
    add[rt] = 0;
    mul[rt] = 0;
    if(l == r){
        scanf("%lld",&tree[rt]);
        tree1[rt] = tree[rt]*tree[rt];
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
int main() {
	int n, m;
	cin >> n >> m;

	return 0;
}