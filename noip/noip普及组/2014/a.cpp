/*
#include <bits/stdc++.h>
using namespace std;
int a[110], vis[20010];
bool vis1[20010];
int main() {
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i], vis[a[i]]++;
	
	for(int i = 1; i <= n; i ++) {
		for(int j = i+1; j <= n; j ++) {
			int tmp = a[i] + a[j];
			if(vis[tmp] && !vis1[tmp]) {
				ans += vis[tmp];
				vis1[tmp] = 1;
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int a[110];
bool vis[110];
int main() {
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) {
		for(int j = i+1; j < n; j ++) {
			for(int k = 0; k < n; k ++) {
				if(i == k || j == k) continue;
				if(a[i]+a[j] == a[k] && !vis[k]) {
					ans++;
					vis[k] = 1;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;
const int N = 9999999;
int a[N], sum[N];
int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << sum[r] - sum[l-1] << endl;
	}
	return 0;
}


*/
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[10] ={1, 2, 3, 4,4, 5, 6, 7};
	int n = lower_bound(a,a+8,4)-a;
	cout << n << endl;
	return 0;
}
*/