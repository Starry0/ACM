#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1000000007;
ll n, k, a[110],f[110];
int main(){
	cin >> n >> k;
	ll sum = 0;
	for(int i = 1; i <= n; i ++) cin >> f[i];
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++){
		sum += (a[i]*f[n-i+1])%mod;
	}
	cout << sum << endl;
	return 0;
}