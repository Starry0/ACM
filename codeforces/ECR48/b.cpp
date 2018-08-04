#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int n, m, q, l, r;
char s[N], t[N];
int a[N], cnt, sum[N];
int main() {
	cin >> n >> m >> q;
	cin >> s >> t;
	int tmp = 0;
	for(int i = 0; i < n; i ++) {
		if(s[i] == t[0]) {
			int cnt = 0;
			for(int j = 0; j < m; j ++) {
				if(s[i+j] == t[j]) cnt++;
				else break;
			}
			if(cnt == m) tmp += 1;
		}
		sum[i+1] = tmp;
	}
	// for(int i = 1; i <= n;i ++) printf("%d %d\n",i,sum[i]);
	while(q--) {
		cin >> l >> r;
		r = r-m+1;
		if(l > r) printf("0\n");
		else printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}