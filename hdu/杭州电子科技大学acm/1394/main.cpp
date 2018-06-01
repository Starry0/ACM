#include <iostream>
#include <cstdio>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
const int maxn = 5e3+10;

int min(int a, int b){
    return a>b?b:a;
}
int sum[maxn<<2], a[maxn];
void PushUP(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l, int r, int rt){
    sum[rt] = 0;
    if(l == r)return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
int query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if(m >= L) ans +=query(L, R, lson);
    if(m < R) ans += query(L, R, rson);
    return ans;
}
void update(int p, int l, int r, int rt){
    if(l == r){
        sum[rt]++;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p,lson);
    else update(p,rson);
    PushUP(rt);
}
int main(){
    int n;
    while(cin>>n){
        int sn = 0;
        build(0, n - 1, 1);
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            sn += query(a[i], n - 1, 0, n -1, 1);
            update(a[i], 0, n - 1, 1);
        }
        int ans = sn;
        for(int i = 0; i < n; i++){
            sn = sn - a[i] + n - a[i] - 1;
            if(sn < ans){
                ans = sn;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[5005],b[5005];
int main(){
    int n;
    while(cin>>n){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(a[i] > a[j]){
                    b[i]++;
                }
            }
            sum += b[i];
        }
        int minx = sum;
        for(int i = 0; i < n; i++){
            sum = sum - a[i] + (n - a[i] - 1);
            if(sum < minx){
                minx = sum;
            }
        }
        cout << minx << endl;
    }
    return 0;
}*/
