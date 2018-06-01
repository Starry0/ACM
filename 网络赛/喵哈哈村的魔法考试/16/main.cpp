/*#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = 1e6+10;
using namespace std;
ll flo[maxn<<2];
void PushUP(int rt){
    flo[rt] = flo[rt<<1] + flo[rt<<1|1];
}
void build(int l, int r, int rt){
    if(l == r){
        scanf("%lld",&flo[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void update(int L, int R, ll add, int l, int r, int rt){
    if(L <= l && r <= R){
        flo[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if(m >= L) update(L, R, add, lson);
    if(m < R) update(L, R, add, rson);
    //PushUP(rt);
}
void query(int l, int r, int rt, ll k){
    if(l == r){
        printf("%lld ",flo[rt]+k);
        return;
    }
    int m = (l + r) >> 1;
    if(m >= l) query(lson,k+flo[rt]);
    if(m < r) query(rson,k+flo[rt]);
}
int main()
{
    int n, m;
    while(cin>>n>>m){
        memset(flo, 0, sizeof(flo));
        build(1, n, 1);
        ll a, b, c;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            update(a, b, c, 1, n, 1);
        }
        query(1, n, 1, 0);
        printf("\n");
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+10;
ll a[maxn], b[maxn];
int main(){
    int n, m;
    while(cin>>n>>m){
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= n; i++){
            scanf("%lld",&a[i]);
        }
        for(int i = 1; i <= m; i++){
            ll l, r, val;
            scanf("%d%d%lld",&l,&r,&val);
            b[l] += val;
            b[r+1] -= val;
        }
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            sum += b[i];
            a[i] += sum;
        }
        for(int i = 1; i <= n; i++){
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
