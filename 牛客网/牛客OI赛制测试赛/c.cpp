#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N], s, k;
set<ll> st;
int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i ++) {
		s += a[i];
		st.insert(s);
	}
	while(q--) {
		scanf("%lld",&k);
		if(s%k != 0) {
			printf("No\n");
			continue;
		}
		ll tmp = s/k;
		bool flag = true;
		for(int i = 1; i <= k; ++i) {
			if(!st.count(tmp*i)) {
				flag = false;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}