#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], cnt[N];
vector<int> vs;
int main() {
	int n;
	int max1 = 0, max2 = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(max1 < a[i]) {
			max2 = max1;
			max1 = a[i];
			cnt[a[i]]--;
		} else if(max2 < a[i]) {
			cnt[max1]++;
			max2 = a[i];
		}
	}
	int MAX = -1000000, ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(cnt[i] > MAX) {
			ans = i;
			MAX = cnt[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}