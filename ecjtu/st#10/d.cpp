#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int MAX = 1e5;
ll mul[MAX], add[MAX];

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b){
        x = 1; y = 0;
    }else{
        exgcd(b, a%b, y, x);
        y -= x*(a/b);
    }
}
ll inv(ll a, ll n) {
    ll x, y;
    exgcd(a, n, x, y);
    return (x+n)%n;
}
void init() {
    add[0] = add[1] = 0;
    add[2] = 2;
    mul[0] = mul[1] = 1;
    mul[2] = 2;
    for(int i = 3; i < MAX; i ++) {
        add[i] = add[i-1] + i;
        mul[i] = (mul[i-1]*i)%mod;
    }
}
int main() {
    //std::ios::sync_with_stdio(false);
    int t;
    ll n;
    scanf("%d",&t);
    init();
    while(t--) {
        scanf("%lld",&n);
        if(n <= 4){
            printf("%lld\n",n);
            continue;
        }
        int l = 2, r = MAX - 5;
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(add[m] <= n) l = m;
            else r = m-1;
        }
        ll tmp = n-add[l];
        if(tmp == l) printf("%lld\n",mul[l]*inv(2,mod)%mod*(l+2)%mod);
        else if(tmp == 0) printf("%lld\n",mul[l]);
        else printf("%lld\n",mul[l-tmp]*mul[l+1]%mod*inv(mul[l-tmp+1],mod)%mod);
    }
    return 0;
}
