/*#include <bits/stdc++.h>
using namespace std;
int n, m, ans;

void dfs(int x, int pre) {
	if(x < 0) return;
	if(x == 0) {
		ans ++;
		return;
	}
	for(int i = pre-1; i > 0; i --) {
		int y = x - i;
		dfs(y, i);
	}
}

int main() {
	cin >> n >> m;
	dfs(m, n+1);
	cout << ans << endl;
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int dfs(int n, int m) {
	if(n < 1 || m < 1) return 0;
	if(n > m) n = m;
	int sum = 0;
	if(n == m) sum ++;
	sum += dfs(n-1,m);
	sum += dfs(n-1,m-n);
	return sum;
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << dfs(n,m) << endl;
	return 0;
}