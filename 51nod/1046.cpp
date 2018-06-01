#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
ll a, b, c;
ll fun(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans*a)%c;
		a = (a*a)%c,b/=2;
	}
	return ans%c;
	
}
int main(){
	cin >> a >> b >> c;
	cout << fun(a%c,b) % c << endl;
	return 0;
}