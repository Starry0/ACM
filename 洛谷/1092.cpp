#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
const int N = 30;
ll n, a[N], ans1, ans2, ans3;
bool vis[N];
char str1[N], str2[N], str3[N];

void dfs(int x) {
	if(x == n) {
		int len1 = strlen(str1), len2 = strlen(str2), len3 = strlen(str3);
		ans1 = ans2 = ans3 = 0;
		ll tmp = 1;
		for(int i = len1-1; i >= 0; i --) {
			ans1 += a[str1[i]-'A']*tmp;
			tmp *= n;
		}
		tmp = 1;
		for(int i = len2-1; i >= 0; i --) {
			ans2 += a[str2[i]-'A']*tmp;
			tmp *= n;
		}
		tmp = 1;
		for(int i = len3-1; i >= 0; i --) {
			ans3 += a[str3[i]-'A']*tmp;
			tmp *= n;
		}
		if(ans1 + ans2 == ans3) {
			for(int i = 0; i < n; i ++) {
				printf("%d%c",a[i],(i==n-1)?'\n':' ');
			}
		}
		return;
	}
	for(int i = 0; i < n; i ++) {
		if(!vis[i]) {
			a[x] = i;
			vis[i] = true;
			dfs(x+1);
			vis[i] = false;
		}
	}
}

int main() {
	cin >> n;
	cin >> str1 >> str2 >> str3;
	dfs(0);
	return 0;
}