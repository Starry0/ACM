#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, l, r;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> l >> r;
		ans += (r-l+1);
	}
	printf("%d\n",ans);
	return 0;
}