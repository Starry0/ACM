#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll a[1010][1010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= max(n,m); i ++){
		a[i][1] = a[1][i] = 1LL;
	}
	for(int i = 2; i <= n; i ++){
		for(int j = 2; j <= m; j ++){
			a[i][j] = (a[i-1][j]+a[i][j-1])%mod;
		}
	}
	cout << a[n][m] << endl;
	return 0;
}