#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110], b[110], c[110];
int main() {
	cin >> n >> m;
	int len = 0;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= m; i ++) cin >> b[i], len+=b[i];
	bool flag = false;
	for(int i = 1; i <= n-len+1; i ++) {
		memset(c,0,sizeof(c));
		for(int j = 1; j <= len; j ++) {
			c[a[i+j-1]]++;
		}
		int j;
		for(j = 1; j <= m; j ++) {
			if(c[j] < b[j]) break;
		}
		if(j == m+1) flag = true;
	}
	if(flag)printf("YES\n");
	else printf("NO\n");
	return 0;
}