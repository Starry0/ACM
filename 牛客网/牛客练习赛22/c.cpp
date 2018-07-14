/*#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
std::vector<int> v[101];
bool vis[N];
int ans = 0, n, l, r;
void dfs(int x, int cnt) {
	if(vis[cnt]) return ;
	if(x == n) {
		vis[cnt] = 1;
		ans++;
		return;
	}
	for(int i = v[x+1].size()-1; i >= 0; i --) {
		dfs(x+1,cnt+v[x+1][i]*v[x+1][i]);
	}
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> l >> r;
		for(int j = l; j <= r; j ++) {
			v[i].push_back(j);
		}
	}
	dfs(0,0);
	cout << ans << endl;
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
bitset<N> a, b;

int main() {
	int n, l, r;
	cin >> n;
	b[0] = 1;
	for(int i = 0; i < n; i ++) {
		cin >> l >> r;
		for(int j = l; j <= r; j ++) {
			a |= (b<<(j*j));
		}
		b = a;
		a.reset();
	}
	cout << b.count() << endl;
	return 0;
}

