#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
ll sum[10];
ll POW(ll x, ll y) {
	ll ans = 1;
	for(ll i = 1; i <= y; i ++) ans *= x;
	return ans;
}

int fun(int de, int n) {
	if(de == 1) return n;
	// printf("%d %d\n",de,n);
	int ans = de*POW(26,de)/26;
	int cnt = n/ans;
	n = n - cnt*ans;
	if(n%de == 1 || n == 1) return cnt+1;
	fun(de-1,n-(n+de-1)/de);
}

int main() {
	int n;
	cin >> n;
	n++;
	for(int i = 1; i <= 7; i ++) sum[i] = i*POW(26,i), sum[i] += sum[i-1];
	for(int i = 1; i <= 7; i ++) {
		if(sum[i] >= n && n > sum[i-1]) {
			printf("%c\n",fun(i,n-sum[i-1])+'A'-1);
		}
	}
	return 0;
}