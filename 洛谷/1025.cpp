// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
void dfs(int sum, int cnt, int pre){
	if(sum == n && cnt == k) {
		ans++;return;
	}
	if(cnt >= k) return;
    for(int i = pre; sum+i*(k-cnt) <= n; i ++) {
        dfs(sum+i, cnt+1, i);
    }
}
int main() {
	cin >> n >> k;
	dfs(0,0,1);
	cout << ans << endl;
	return 0;
}
