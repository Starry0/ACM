#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e6+10;
// int a[N];
struct Nod {
	ll id, num;
}e[10];
ll max(ll x, ll y) {
	return x > y ? x : y;
}
// ll abs(ll x) {
// 	return x<0?-x:x;
// }
ll x;
int main() {
	int t, n, A, B;
	cin >>t;
	for(int ca = 1; ca <= t; ++ ca) {
		cin >> n >> A >> B;
		for(int i = 1; i <= 8; i ++) {
			if(i <= 4) e[i].num = 1e8;
			else e[i].num = -1e8;
		}
		for(int i = 1; i <= n; ++ i) {
			scanf("%lld", &x);
			if(abs(x) <= e[1].num) {
				e[2].num = e[1].num, e[2].id = e[1].id;
				e[1].num = abs(x), e[1].id = i;
			} else if(abs(x) < e[2].num) {
				e[2].num = abs(x);e[2].id = i;
			}
			if(x <= e[3].num) {
				e[4].num = e[3].num, e[4].id = e[3].id;
				e[3].num = x, e[3].id = i;
			} else if(x < e[4].num) {
				e[4].num = x;e[4].id = i;
			}
			if(abs(x) >= e[5].num) {
				e[6].num = e[5].num, e[6].id = e[5].id;
				e[5].num = abs(x), e[5].id = i;
			} else if(abs(x) > e[6].num) {
				e[6].num = abs(x);e[6].id = i;
			}
			if(x >= e[7].num) {
				e[8].num = e[7].num, e[8].id = e[7].id;
				e[7].num = x, e[7].id = i;
			} else if(abs(x) > e[8].num) {
				e[8].num = x;e[8].id = i;
			}
		}
		// for(int i = 1; i <= 8; i ++) printf("%lld %lld\n",e[i].id,e[i].num);
		ll ans = -1e12;
		if(A < 0 && B < 0) {
			ans = max(ans, max(A*e[1].num*e[1].num+B*(e[3].id==e[1].id?e[4].num:e[3].num), A*e[2].num*e[2].num+B*(e[3].id==e[2].id?e[4].num:e[3].num)));
		} else if(A < 0 && B >= 0) {	
			ans = max(ans, max(A*e[1].num*e[1].num+B*(e[7].id==e[1].id?e[8].num:e[7].num), A*e[2].num*e[2].num+B*(e[7].id==e[2].id?e[8].num:e[7].num)));
		} else if(A >= 0 && B < 0) {
			ans = max(ans, max(A*e[5].num*e[5].num+B*(e[3].id==e[5].id?e[4].num:e[3].num), A*e[6].num*e[6].num+B*(e[3].id==e[6].id?e[4].num:e[3].num)));
		} else if(A >= 0 && B >= 0) {
			ans = max(ans, max(A*e[5].num*e[5].num+B*(e[5].id==e[7].id?e[8].num:e[7].num), A*e[6].num*e[6].num+B*(e[6].id==e[7].id?e[8].num:e[7].num)));
		}
		printf("Case #%d: %lld\n",ca,ans);
	}
	return 0;
}