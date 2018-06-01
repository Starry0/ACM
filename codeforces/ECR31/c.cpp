#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100010;
int fa[N], cnt[N];
bool vis[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> fa[i];
	for(int i = 1; i <= n; i ++) {	
		if(!vis[i]) {
			ll ans = vis[i] = 1, tmp = fa[i];
			while(!vis[tmp]) {
				ans ++;
				vis[tmp] = true;
				tmp = fa[tmp];
			}
			cnt[i] = ans;
		}
	}
	sort(cnt+1, cnt+1+n);
	ll sum = 0;
	if(n > 1) sum = (ll)(cnt[n]+cnt[n-1])*(ll)(cnt[n]+cnt[n-1]);
	else sum = 1;
	for(int i = 1; i <= n-2; i ++) {
		sum += (ll)cnt[i]*(ll)cnt[i];
	}
	printf("%lld\n",sum);
	return 0;
}

/*
100

98 52 63 2 18 96 31 58 84 40 41 45 66 100 46 71 26 48 81 20 73 91 68 76 13 93 17 29 64 95 79 21 55 75 19 85 54 51 89 78 15 87 43 59 36 1 90 35 65 56 62 28 86 5 82 49 3 99 33 9 92 32 74 69 27 22 77 16 44 94 34 6 57 70 23 12 61 25 8 11 67 47 83 88 10 14 30 7 97 60 42 37 24 38 53 50 4 80 72 39

*/
