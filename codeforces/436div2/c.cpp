#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int a, b, f, k, cnt = 0, ans = 0;
	cin >> a >> b >> f >> k;
	if(k == 1 && (f > b || (a-f) > b)) return 0*printf("-1\n");
	else if(k == 2 && (f > b || 2*(a-f) > b)) return 0*printf("-1\n");
	else if(k >= 3 && (2*f > b || 2*(a-f) > b)) return 0*printf("-1\n");
	for(cnt = b; k > 0; f = a - f, --k) {
		if(f > b || (a-f) > b) return 0*printf("-1\n");
		else if(cnt >= a + (k != 1 ?a-f:0)) cnt -= a;
		else cnt = b - (a - f), ans ++;
	}
	printf("%d\n",ans);
	return 0;
}