#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[40];
map<int,int> mp;
int main() {
	int n, q, x;;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		mp[x] ++;
	}
	for(int i = 0; i < 32; i ++) {
		a[i] = mp[1<<i];
	}
	while(q--) {
		scanf("%d",&x);
		int ans = 0;
		for(int i = 31; i >= 0; i --) {
			int tmp = 1<<i;
			if(tmp <= x) {
				int cnt = min(a[i],x/tmp);
				ans += cnt;
				x -= cnt*tmp;
			}
		}
		if(x == 0) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}