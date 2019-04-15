/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2+10;
int a[N][N], b[N][N];
int cnt[N];
int init(int x, int y) {
	int ans = 0;
	for(int k = 3; k <= x; k ++) {
		for(int q = 3; q <= y; q ++) {
			ans += (x-k+1)*(y-q+1)*(k-2)*(q-2)*(k-1)*(q-1)/4;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	// for(int i = 1; i <= 7; i ++) {
	// 	for(int j = 1; j <= 7; j ++) {
	// 		printf("%d ",a[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(int i = 3; i <= 10; i ++) printf("%8d",i);
		printf("\n");
	for(int i = 3; i <= 10; i ++) {
		for(int j = 3; j <= 10; j ++) {
			printf("%8d",init(i,j));
		}
		printf("\n");
	}
	// printf("------------------\n");
	// for(int i = 0; i < 10; i ++) printf("%5d ",i);
	// 	printf("\n");
	// for(int i = 1; i <= 10; i ++) {
	// 	printf("%5d ",i);
	// 	for(int j = 1; j <= 10; j ++) {
	// 		printf("%5d ",a[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("------------------\n");
	// for(int i = 0; i < 10; i ++) printf("%5d ",i);
	// 	printf("\n");
	// for(int i = 1; i <= 10; i ++) {
	// 	printf("%5d ",i);
	// 	for(int j = 1; j <= 10; j ++) {
	// 		printf("%5d ",b[i][j]);
	// 	}
	// 	printf("\n");
	// }
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		
	}
	return 0;
}*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll cnt[N];
const ll mod = 1e9+7;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll t,x,y;
	cnt[3] = 1; cnt[4] = 5;
	for(ll i = 5; i <= N; i ++) {
		cnt[i] = ((2*cnt[i-1]+(i-1)*(i-2)/2-cnt[i-2])%mod+mod)%mod;
	}
	// for(int i = 1; i <= 1000; i ++) printf("%d %lld\n",i,cnt[3]*cnt[i]%mod );
	cin >> t;
	for(int ca = 1; ca <= t; ca++) {
		cin>>x>>y;
		printf("Case %d: %lld\n",ca, cnt[x]*cnt[y]%mod);
	}
	return 0;
}