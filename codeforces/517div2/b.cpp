#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], b[N], c[N];
int main() {
	int n, j, k, i;
	cin >> n;
	for(i = 1; i < n; i ++) cin >> a[i];
	for(i = 1; i < n; i ++) cin >> b[i];
	for(i = 0; i < 4; i ++) {
		c[0] = i;
		for(j = 1; j < n; j ++) {
			for(k = 0; k < 4; k ++) {
				if((k|c[j-1]) == a[j] && (k&c[j-1]) == b[j]) {
					c[j] = k;
					break;
				}
			}
			if(k == 4) break;
		}
		if(j == n) break;
	}
	if(i == 4) return 0*printf("NO\n");
	printf("YES\n");
	for(int i = 0; i < n; i ++) printf("%d ",c[i]);
	return 0;
}