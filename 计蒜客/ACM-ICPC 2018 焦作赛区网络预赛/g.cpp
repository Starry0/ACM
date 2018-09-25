#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int mod1 = 1e9+6;
const int N = 1e5+10;
char s[N];
ll pow_mod(ll x, ll n){  
    ll res=1;  
    while(n>0){  
        if(n&1)res=res*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return res;  
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		scanf("%s", s);
		ll cnt = s[0] - '0';
		for(int i = 1; s[i]; i ++) {
			cnt = (cnt*10+s[i]-'0')%mod1;
		}
		cnt--;
		printf("%lld\n",pow_mod(2, cnt));
	}
	return 0;
}