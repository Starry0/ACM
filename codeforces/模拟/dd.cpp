#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1000010
#define INF 0x3f3f3f3f
#define lson rt<<1, l, m
#define rson rt<<1|1, m+1, r
LL tree[N<<2];

void pushup(int rt) { tree[rt] = tree[rt<<1] + tree[rt<<1|1]; }

void update(int rt, int l, int r, int id) {
    if(l == r && l == id) {
        tree[rt]++;
        return ;
    }
    int m = (l + r) >> 1;
    if(id <= m) update(lson, id);
    else update(rson, id);
    pushup(rt);
}

LL query(int rt, int l, int r, int L, int R) {
    LL ans = 0;
    if(L <= l && r <= R) return tree[rt];
    int m = (l + r) >> 1;
    if(L <= m) ans += query(lson, L, R);
    if(m < R) ans += query(rson, L, R);
    return ans;
}

LL getsum(int l, int r, int n) {
    LL ans = 0;
    if(l > r) {
        ans += query(1, 1, n, l, n);
        ans += query(1, 1, n, 1, r);
    } else {
        ans += query(1, 1, n, l, r);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int now = 1 + k, pre;
    if(k > n / 2) k = n - k;
    LL res = 1;
    for(int i = 1; i <= n; i++) {
        pre = now; update(1, 1, n, pre);
        now += k; if(now > n) now -= n;
        res += getsum(pre, now, n) - 1;
        printf("%lld ",(i==n) ? res : res+1);
        update(1, 1, n, now);
    }
    printf("\n");
    return 0;
}
