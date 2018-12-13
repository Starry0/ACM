#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const ll mod = 1e9+7;
ll f[N], n;
int main() {
    f[1] = 1, f[2] = 2;
    for(int i = 3; i <= 1000; i ++) f[i] = (2*f[i-1]+3*f[i-2]+i)%mod;
    while(cin>>n) {
        if(n==0)break;
        printf("%lld\n",f[n]);
    }
    return 0;
}
