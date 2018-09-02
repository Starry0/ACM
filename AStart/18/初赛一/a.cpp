#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i ++) cin >> a[i];
		sort(a,a+n);
		int ans = -1;
		for(int i = n-1; i >= 2; i --) {
			if(a[i-1]+a[i-2] > a[i]) ans = max(ans, a[i]+a[i-1]+a[i-2]);
		}
		cout << ans << endl;
	}
	return 0;
}