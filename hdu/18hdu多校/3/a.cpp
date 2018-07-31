#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7+10;
ll t,n,m,k,q,p,r,mod;
int a[N];
int b[N][3];
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &k, &p, &q, &r, &mod);
		for(int i = 1; i <= k; i ++) scanf("%d", &a[i]);
		for(int i = k+1; i <= n; i ++) {
			a[i] = (p*a[i-1]+q*i+r)%mod;
		}
		int A = 0, B = 0;
		int MAX = 0, count = 0;
		for(int i = 1; i <= n-m+1; i ++) {
			
		}
		printf("%d %d\n",A,B);
	}
	return 0;
}