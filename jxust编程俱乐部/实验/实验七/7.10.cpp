#include <stdio.h>
#define ll long long
const ll mod = 12345678;
ll a[110][110];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) a[i][1] = a[i][i] = 1;
	a[1][1] = 1;
	for(int i = 2; i <= n; i ++) {
		for(int j = 2; j <= i; j ++) {
			a[i][j] = (a[i-1][j] + a[i-1][j-1])%mod;
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= i; j ++) {
			printf("%lld%c",a[i][j],j==i?'\n':' ');
		}
	}
	
	return 0;
}