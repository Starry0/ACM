#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int x[N], y[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> x[i] >> y[i];
	int cnt = max(x[1],y[1]);
	for(int i = 2; i <= n; i ++) {
		if(cnt >= max(x[i],y[i])) {
			cnt = max(x[i],y[i]);
		} else if(cnt >= min(x[i],y[i])) {
			cnt = min(x[i], y[i]);
		} else return 0*printf("NO\n");
	}
	printf("YES\n");
	return 0;
}
