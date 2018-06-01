#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	int t;
	ll n,m;
	//cout << (4.1) << endl;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll ans = 0;
		ll cnt = 1,sum = 0;
		while(cnt <= m && sum < n){
			ans++;
			sum = sum + cnt;
			cnt = cnt*2;
		}
		if(sum >= n){
			cout << ans << endl;
			continue;
		}
		if(cnt > m){
			cnt = m;
			ll sh = n-sum;
			ans = ans + sh/cnt;
			if(sh%cnt!=0)ans++;
			cout << ans << endl;
		}
	}
	return 0;
}