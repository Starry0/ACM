#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int t, n, x;
int cnt[1010];
struct Nod{
	int num, a;

}e[N];

bool cmp(Nod a, Nod b) {
	if(1.0*a.a/a.num !=  1.0*b.a/b.num)return 1.0*a.a/a.num > 1.0*b.a/b.num;
	else return a.a > b.a;
}

int main() {
	for(int i = 1; i <= 1000; i ++) {
		cnt[i] = cnt[i-1] + i;
	}
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n;
		ll ans = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%d%d", &x, &e[i].a);
			ans += e[i].a;
			e[i].num = lower_bound(cnt+1,cnt+1000,x) - cnt;
		}
		sort(e+1,e+1+n,cmp);
		ll cnt = 0;
		for(int i = 1; i <= n; i ++) {
			// printf("%d %d\n",e[i].num,e[i].a);
			cnt += e[i].num*ans;
			ans -= e[i].a;
		}
		printf("Case #%d: %lld\n",ca,cnt);

	}
	return 0;
}