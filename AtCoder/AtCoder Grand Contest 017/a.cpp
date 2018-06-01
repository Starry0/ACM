#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;

int a[55];
ll C(ll a, ll n){
	ll ans = 1;
	for(ll i = 0; i < a; i ++){
		ans*=(n-i);
		ans/=(i+1);
	}
	return ans;
}
int main(){
	int n,p;
	cin>>n>>p;
	for(int i = 1; i <= n; i ++)cin>>a[i];
	ll aa = 0,bb = 0,ans = 0;
	for(int i = 1; i <= n; i ++){
		if(a[i]%2)aa++;
		else bb++;
	}
	if(p == 1){
		if(aa == 0){
			printf("0\n");
			return 0;
		}
		for(ll i = 1; i <= aa; i+=2){
			ans+=C(i,aa);
		}
		ll ans1 = 0;
		for(ll i = 0; i <= bb; i ++){
			ans1 += C(i,bb);
		}
		cout << ans*ans1 << endl;
	}else {
		for(ll i = 0; i <= bb; i++)
			ans+=C(i,bb);
		ll ans1 = 0;
		for(ll i = 0; i <= aa; i+=2)
			ans1+=C(i,aa);
		cout << ans1*ans<<endl;
	}
	return 0;
}