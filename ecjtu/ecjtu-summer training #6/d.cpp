/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int Mod = 1000000007;
ll n,m,k,d;
ll a[220], C[220][220];
inline void getC(){
	memset(C,0,sizeof(C));
	for(int i =0; i < 220; i ++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j ++){
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%Mod;
		}
	}
}
int main(){
	int t;
	getC();
	//cout << C[5][3]<<endl;
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		memset(a,0,sizeof(a));
		for(ll i = 1; i <= n; i ++)cin>>a[i];
		int cnt = count_if(a+1,a+n+1,bind2nd(greater_equal<int>(),d));
		ll ans = 0;
		for(int i = k; i <= cnt; i ++){
			if(n-cnt == 0)break;
			if(m-i<0)break;
			ans = (ans+(C[cnt][i]*C[n-cnt][m-i])%Mod)%Mod;
		}
		if(n==cnt)ans = C[cnt][m];
		if(cnt < k || n < m) printf("0\n");
		else cout << ans%Mod << endl;
	}
	return 0;
}*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int Mod = 1000000007;
ll n,m,k,d;
ll a[220],C[220][220];
void getC(){
	memset(C,0,sizeof(C));
	for(int i = 0; i < 220; i ++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j ++){
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%Mod;
		}
	}
}
int main(){
	int t;
	getC();
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		memset(a,0,sizeof(a));
		for(ll i = 1; i <= n; i ++)cin>>a[i];
		int cnt = count_if(a+1,a+n+1,bind2nd(greater_equal<int>(),d));
		ll ans = 0;
		for(ll i = m>=cnt?cnt:m; i >= k; i --){
			ans = (ans+(C[cnt][i]%Mod)*(C[n-cnt][m-i]%Mod))%Mod;
		}
		cout << ans%Mod << endl;
	}
	return 0;
}