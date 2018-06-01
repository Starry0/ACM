#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100010;
ll a[N];
void solve() {
    ll n, ans = 0;
    scanf("%lld", &n);
    for(int i = 0; i < n; i ++) scanf("%lld", &a[i]);
    sort(a,a+n);
    for(int i = 0; i < n; i ++) {
        for(int j = i+1; j < n; j ++) {
            ll x = (a[i]+a[j])/(a[i]*a[j]);
            if(x < 1) break;
            ans += x;
        }
    }
    printf("%lld\n",ans);
}
void solve1() {
    ll n, c1 = 0, c2 = 0, cc = 0;
    scanf("%lld", &n);
    int x;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &x);
        if(x == 1) c1 ++;
        else if(x == 2) c2 ++;
        else cc ++;
    }
    printf("%lld\n",c1*(n-1)+c2*(c2-1)/2);
}
int main() {
    solve1();
    return 0;
}
