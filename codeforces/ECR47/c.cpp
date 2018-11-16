#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, m, cnt1 = 0, cnt2 = 0, x, d;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cnt1+=abs(1-i);
	for(int i = 1; i <= n; i ++) cnt2+=abs((n+1)/2-i);
	ll ans1 = 0, ans2 = 0;
	while(m--) {
		cin >> x >> d;
		ans1 += x;
		ans2 += (d<0)?(d*min(cnt1,cnt2)):(d*max(cnt2,cnt1));
	}
	printf("%.12lf\n",(1.0*ans1+1.0*ans2/n));
	return 0;
}