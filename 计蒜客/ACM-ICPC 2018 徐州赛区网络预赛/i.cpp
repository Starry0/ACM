#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
char s[N];
int main() {
	int t, n;
	char L;
	scanf("%d", &t);
	while(t--) {
		cin >> n >> L;
		int ans = 0;
		cin >> s;
		int i;
		for(i = 0; i < n; i ++) {
			if(s[i] != L) break;
		}
		if(i == n) {
			printf("1\n");
			continue;
		}
		ans += (n-i-1)*2;
		if(abs(s[i]-L) >= 10) ans+=2;
		else ans++;
		printf("%d\n",ans);
	}
	return 0;
}