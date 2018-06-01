// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int N = 1e5+10;
// int n, m, cnt, x, y, k, root[N], a[N];
// struct node{int l, r, sum;}T[N*40];
// vector<int> vs;
// int getid(int x) {return lower_bound(vs.begin(),vs.end(),x)-vs.begin()+1;}
// void update(int l, int r, int &x, int y, int pos) {
//     T[++cnt] = T[y], T[cnt].sum++, x =cnt;
//     if(l == r) return;
//     int m = (l+r)>>1;
//     if(m >= pos) update(l, m, T[x].l, T[y].l, pos);
//     else update(m+1, r, T[x].r, T[y].r, pos);
// }
// int query(int l, int r, int x, int y, int k){
//     if(l == r) return l;
//     int m = (l+r)>>1;
//     int sum = T[T[y].l].sum - T[T[x].l].sum;
//     if(sum >= k) query(l, m, T[x].l, T[y].l, k);
//     else query(m+1, r, T[x].r, T[y].r, k-sum);
// }
// int main() {
//     scanf("%d %d", &n, &m);
//     for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), vs.push_back(a[i]);
//     sort(vs.begin(),vs.end()), vs.erase(unique(vs.begin(),vs.end()),vs.end());
//     printf("%d\n",getid(a[2]));
//     for(int i = 1; i <= n; i ++) update(1,n,root[i],root[i-1],getid(a[i]));
//     for(int i = 1; i <= m; i ++) {
//         scanf("%d%d%d",&x, &y, &k);
//         printf("%d\n",vs[query(1,n,root[x-1],root[y],k)-1]);
//     }
//     return 0;
// }


#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N], b[N], root[N*20], ls[N*20], rs[N*20], sum[N*20];
int sz, n, q, ql, qr, k, cnt;
void Build(int l, int r, int &o){
    o = ++cnt;
    sum[o] = 0;
    if(l == r) return;
    int m = (l+r) >> 1;
    Build(l, m, ls[o]);
    Build(m+1, r, rs[o]);
}
void update(int &o, int last, int l, int r, int pos) {
    o = ++ cnt;
    ls[o] = ls[last];
    rs[o] = rs[last];
    sum[o] = sum[last] + 1;
    if(l == r) return;
    int m = (l+r) >> 1;
    if(pos <= m) update(ls[o], ls[last], l, m, pos);
    else update(rs[o], rs[last], m+1, r, pos);
}

int query(int ss, int tt, int l, int r, int k) {
    if(l == r) return l;
    int m = (l+r) >> 1;
    int tot = sum[ls[tt]] - sum[ls[ss]];
    if(k <= tot) return query(ls[ss], ls[tt], l, m, k);
    else return query(rs[ss], rs[tt], m+1, r, k-tot);
}
int main() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b+1, b+1+n);
    sz = unique(b+1,b+1+n)-(b+1);
    cnt = 0;
    Build(1, sz, root[0]);
    for(int i = 1; i <= n; i ++) a[i] = lower_bound(b+1,b+1+sz,a[i]) - b;
    for(int i = 1; i <= n; i ++) update(root[i], root[i-1], 1, sz, a[i]);
    // for(int i = 1; i <= n; i ++) printf("%d ",root[i] );printf("\n");
    while(q--) {
        scanf("%d%d%d", &ql, &qr, &k);
        int ans = query(root[ql-1], root[qr], 1, sz, k);
        printf("%d\n",b[ans]);
    }
    return 0;
}
