#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int root[N*20], ls[N*20], rs[N*20], a[N], b[N], sum[N];
int t, L, R, H, cnt, sz, n, m;
void build(int &o, int l, int r) {
    o = ++cnt;
    sum[o] = 0;
    if(l == r) return ;
    int m = (l+r) >> 1;
    build(ls[o], l, m);
    build(rs[o], m+1, r);
}
void update(int l, int r, int &o, int last, int pos) {
    o = ++cnt;
    ls[o] = ls[last];
    rs[o] = rs[last];
    sum[o] = sum[last] + 1;
    if(l == r) return ;
    int m = (l+r) >> 1;
    if(pos <= m) update(l, m, ls[o], ls[last], pos);
    else update(m+1, r, rs[o], rs[last], pos);
}
int query1(int ss, int tt, int l, int r, int k) {
    if(k < 0) return 0;
    if(k >= r) return sum[tt]-sum[ss];
    int m = (l+r) >> 1, ret = 0;
    if(k >= l) ret += query1(ls[ss], ls[tt], l, m, k);
    if(k > m) ret += query1(rs[ss], rs[tt], m+1, r, k);
    return ret;
}
int query(int L, int R, int l, int r, int h)
{
    int ans = 0;
    int m = (l + r) >> 1;
    if(l == r) {
        if(h >= l) ans += sum[R] - sum[L];
        return ans;
    }
    if(m < h) {
        ans += sum[ls[R]] - sum[ls[L]]; // 如果 h > m 的话,左子树全部都小于h,全部都加上
        ans += query(rs[L], rs[R], h, m + 1, r);
    } else {
        ans += query(ls[L], ls[R], h, l, m);
    }
    return ans;
}
void debug(int rt, int l, int r)
{
    if(l == r) {
        printf("%d : %d\n", l, sum[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    debug(ls[rt], l, m);
    debug(rs[rt], m+1, r);
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = a[i];
        sort(b+1, b+1+n);
        sz = unique(b+1, b+1+n) - (b+1);
        build(root[0], 1, sz);
        for(int i = 1; i <= n; i ++) a[i] = lower_bound(b+1,b+1+sz,a[i])-b;
        for(int i = 1; i <= n; i ++) update(1, sz, root[i], root[i-1], a[i]);
        debug(root[n], 1, sz);
        for(int i = 1; i <= m; i ++) {
            scanf("%d%d%d", &L, &R, &H);
            L++;R++;
            int ans = query(root[L-1], root[R], 1, sz, lower_bound(b+1,b+1+sz,H)-b);
            printf("%d\n",ans);
        }
    }
    return 0;
}
