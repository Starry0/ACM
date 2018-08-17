#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll MAX = 1e9+10;
ll a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	for(ll two = 1; two < MAX; two *= 2) {
		for(ll three = 1; three*two < MAX; three *= 3) {
			for(ll four = 1; three*two*four < MAX; four *= 5) {
				for(ll five = 1; three*two*four*five < MAX; five *= 7) {
					a[cnt++] = three*two*four*five;
				}
			}
		}
	}
	sort(a,a+cnt);
	ll n;
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld",&n);
		int k = lower_bound(a,a+cnt,n)-a;
		printf("%lld\n",a[k]);		
	}
	return 0;
}