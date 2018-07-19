#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e6+10;
int t, q, p, m, n;
unsigned int sa, sb, sc;
ll a[N], st[N], top;
ll MAX[N];
unsigned int f() {
	sa ^= sa<<16;
	sa ^= sa >> 5;
	sa ^= sa << 1;
	unsigned int t = sa;
	sa = sb;
	sb = sc;
	sc ^= t^sa;
	return sc;
}

int main() {
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ca ++){
		top = 0;
		scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &sa, &sb, &sc);
		for(int i = 1; i <= n; i ++) {
			if(f()%(p+q) < p) {
				int tmp = f()%m+1;
				st[++top] = tmp;
				MAX[top] = max(st[top], MAX[top-1]); 
				a[i] = MAX[top];
			} else{
				if(top == 0) a[i] = 0;
				else a[i] = MAX[--top];
			}
		}
		ll ans = 0;
		for(ll i = 1; i <= n; i ++) {
			ans ^= i*a[i];
		}
		printf("Case #%d: %lld\n",ca,ans);
	}
	return 0;
}