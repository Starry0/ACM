#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll get(ll n,ll x){
	ll ans = 1;
	for(ll i = 1; i <= x; i ++){
		ans*=2;
	}
	//cout << ans << endl;
	if(n%ans){
		ans = n/ans + 1;
	}else {
		ans = n/ans;
	}
	return ans;
}
int main(){
	ll n, q, a = 1;
	//cout << get(12,2) << endl;
	cin >> n >> q;
	ll minn = n, MIN = n;
	for(ll i = 0; ; i ++){
		minn = i*q+get(n,i);
		if(minn <= MIN){
			MIN = minn;
		}else break;
	}
	cout << MIN << endl;
	return 0;
	
}