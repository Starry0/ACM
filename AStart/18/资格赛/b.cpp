#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
char s[N];
int sum[26][N];
int main() {
	int t, n, q, l, r;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		printf("Case #%d:\n",ca);
		memset(sum, 0, sizeof(sum));
		scanf("%d%d", &n, &q);
		scanf("%s", s);
		for(int i = 0; s[i]; i ++) {
			sum[s[i]-'A'][i+1] = 1;
		}
		for(int i = 0; i < 26; i ++) {
			for(int j = 1; j <= n; j ++) {
				sum[i][j] += sum[i][j-1];
			}
		}
		while(q--) {
			scanf("%d%d", &l, &r);
			for(int i = 0; i < 26; i ++) {
				int ans = sum[i][r] - sum[i][l-1];
				if(ans != 0) {
					printf("%d\n",ans);
					break;
				}
			}
		}
	}
	return 0;
}