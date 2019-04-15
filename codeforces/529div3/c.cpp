#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int b[50];
int main() {
	int n, k;
	cin >> n >> k;
	if(n < k) return 0*printf("NO\n");
	for(int i = 0; i <= 30; i ++) {
		b[i] = (n>>i)&1;
	}
	int ans = 0;
	for(int i = 30; i >= 0; i --) if(b[i]) ans++;
	if(ans > k) return 0*printf("NO\n");
	for(int i = 30; i > 0; i --) {
		int cnt = min(b[i], k-ans);
		b[i] -= cnt;
		b[i-1] += cnt*2;
		ans += cnt;
		if(ans == k) break;
	}
	if(ans == k) {
		printf("YES\n");
		for(int i = 0; i <= 30; i ++) {
			if(b[i]) {
				for(int j = 0; j < b[i]; j ++)
				printf("%d ",(1<<i));
			}
		}
	} else printf("NO\n");
	return 0;
}