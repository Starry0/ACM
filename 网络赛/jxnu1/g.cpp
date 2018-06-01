#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int MAX = 1e5;
ll a[MAX];
ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}
int main() {
    std::ios::sync_with_stdio(false);
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        if(n == 1){
            if(a[0] >= 2) puts("Yes");
            else puts("No");
        }else {
            ll ans = gcd(a[0],a[1]);
            for(int i = 2; i <= n; i ++) ans = gcd(ans,a[i]);
            if(ans >= 2)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
