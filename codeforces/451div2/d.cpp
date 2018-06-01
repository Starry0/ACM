/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
int main(){
	int n, x, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		a[x]++;
	}
	int ans = 0;
	for(int i = 0; i < N; i ++) {
		if(a[i]) {
			int tmp = 0;
			for(int j = i; j < i+m; j ++) {
				tmp += a[j];
			}
			if(tmp >= k) ans += tmp-k+1;
		}
	}
	cout << ans <<endl;
	return 0;
}
*/
/*
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
vector<int> vs;
int main() {
	int n, m, k, x;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		vs.push_back(x);
	}
	sort(vs.begin(),vs.end());
	int ans = 0;
	for(int i = 0; i+k-1 < vs.size(); i ++) {
		while(vs[i+k-1] - vs[i] < m && i+k-1 < vs.size()) {
			ans++;
			vs.erase(vs.begin()+i+k-1);
		}
	}
	cout << ans << endl;
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int vis[N], a[N];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a,a+n);
	int l = 0, r = 0, ans = 0, cnt = 1;
	while(r < n) {
		while(a[r]-a[l]+1 > m) {
			if(vis[l] == 0) cnt--;
			l++;
		}
		if(cnt >= k) {
			ans ++;
			vis[r] = 1;
			cnt--;
		} 
		r++;
		cnt++;
	}
	cout << ans << endl;
	return 0;
}