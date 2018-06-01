#include <bits/stdc++.h>
using namespace std;
char str[2010][2010];
int n, m, k;

int main() {
	cin >> n >> m >> k;
	int ans = 0;
	for(int i = 1; i <= n; i ++) cin >> str[i]+1;
	for(int j = 1; j <= m; j ++) {
		for(int i = 1; i <= n; i ++) {
			if(i+k-1 <= n) {
				int tmp = 0;
				for(int l = i; l <= n; l ++) {
					if(str[l][j] == '.') tmp++;
					else break;
				}
				if(tmp >= k) {
					ans += tmp-k+1;
					i += tmp-k+1;
				}
			} else break;
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(j+k-1 <= m) {
				int tmp = 0;
				for(int l = j; l <= m; l ++) {
					if(str[i][l] == '.') tmp++;
					else break;
				}
				if(tmp >= k) {
					ans += tmp-k+1;
					j += tmp-k+1;
				}
			} else break;
		}
	}
	if(k == 1) printf("%d\n",ans/2);
	else printf("%d\n",ans); 
	return 0;
}