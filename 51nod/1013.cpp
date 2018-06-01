#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll long long
using namespace std;
const int mod = 1000000007;
ll pow_mod(ll x, ll n) {
    ll res = 1;
    while(n) {
        if(n&1LL) res = res*x%mod;
        x = x*x%mod;
        n>>=1;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    cout << (pow_mod(3,n+1)-1)*pow_mod(2,mod-2)%mod << endl;
    return 0;
}
