#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int a[N], b[N];
int main() {
	int t, n, x;
	scanf("%d", &t);
	while(t--) {
		scanf("%d",&n);
		memset(a,INF,sizeof(a));
		memset(b,INF,sizeof(b));
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			*upper_bound(a,a+n,x) = x;
			*upper_bound(b,b+n,-x) = -x;
		}
		int ans1 = lower_bound(a,a+n,INF)-a;
		int ans2 = lower_bound(b,b+n,INF)-b;
		if(ans1 >= n-1 || ans2 >= n-1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}