/*#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int w[N], s[N*100];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> w[i];
	for(int i = 1; i <= min(n, m); i ++) {
		for(int j = 1; j <= w[i]; j ++) s[j]++;
	}
	int x = min(n, m)+1, now = 1;
	while(x <= n) {
		while(s[now] == m) now++;
		for(int i = now; i < now+w[x]; i ++) s[i]++;
		x ++;
	}
	while(s[now] > 0) now++;
	printf("%d\n",now-1);
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int w[N], a[110];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> w[i];
	for(int i = 1; i <= m; i ++) a[i] = w[i];
	for(int i = m+1; i <= n; i ++) {
		sort(a+1,a+1+m);
		a[1] += w[i];
	}
	int MAX = 0;
	for(int i = 1; i <= m; i ++) MAX = max(MAX, a[i]);
	cout << MAX << endl;
	return 0;
}