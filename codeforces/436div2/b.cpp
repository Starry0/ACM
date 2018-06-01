#include <bits/stdc++.h>
using namespace std;
const int N = 220;
char str[N];
int vis[30];
int check() {
	int ans = 0;
	for(int i = 0; i < 26; i ++) {
		if(vis[i]) ans++;
	}
	return ans;
}
int main() {
	int n, ans = 0;
	cin >> n >>str;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i ++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			vis[str[i] - 'a'] ++;
		} else {
			int Max = check();
			if(ans < Max) ans = Max;
			memset(vis, 0, sizeof(vis));
		}
	}
	int Max = check();
	if(ans < Max) ans = Max;
	printf("%d\n",ans);
	return 0;
}