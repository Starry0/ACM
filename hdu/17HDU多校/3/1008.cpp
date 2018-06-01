#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll get(ll n, ll k) {
    if(k == 1)return n%mod;
    if(k&1) {
        return n*get((n*n)%mod,k/2)%mod;
    }else return get((n*n)%mod,k/2)%mod;
}
int main() {
    ll n, k, cnt = 1;
    while(cin>>n>>k) {
        printf("Case #%lld: %lld\n",cnt++, get(n%mod,k)%mod);
    }
    return 0;
}
