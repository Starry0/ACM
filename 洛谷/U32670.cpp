#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll q, l, r;
    double a = 94.1, b = 59;
    printf("%f\n",a-b );
    cin >> q;
    while(q--) {
    	scanf("%lld%lld",&l,&r);
    	l = l + (r-l)/9*9;
    	ll ans = 0;
    	for(ll i = l; i <= r; i ++) ans = (ans+i%9)%9;
    	cout << ans << endl;
    }
    return 0;    
} 