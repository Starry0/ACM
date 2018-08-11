#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int main() {
	int t, n;
	cin >> t;
	a[0] = 1;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n;
		int ans = 0, m = sqrt(n), cnt = 1;
		for(int i = 2; i <= m; i ++) {
			if(n%i == 0) {
				a[cnt++] = i;
				if(!(i==m&&m*m==n))a[cnt++] = n/i; 
			}
		}
		// for(int i = 0; i < cnt; i ++) printf("%d ",a[i]);printf("\n");
		sort(a,a+cnt);
		for(int i = 0; i < cnt; i ++) ans += a[i];
		if(ans == n) {
			printf("Case %d: %d = ",ca,n);
			for(int i = 0; i < cnt; i ++) {
				if(i != cnt-1) printf("%d + ",a[i]);
				else printf("%d\n",a[i]);
			}

		} else printf("Case %d: Not perfect.\n",ca);
	}
	return 0;
}