#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vs, st;
int main() {
	/*
	#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);  
    #endif // ONLINE_JUDGE  
	*/
	ll n, x;
	cin >> n;
	ll cnt1 = 0,cnt2 = 0, cnt3 = 0;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		ll tmp = sqrt(x);
		if(x == 0) cnt3 ++;
		if(tmp * tmp == x) {
			cnt1++;
		} else {
			st.push_back(x);
			cnt2++;
		}
	}
	ll ans = 0;
	if(cnt1 > cnt2) {
		cnt1 -= cnt3;
		if(cnt1 >= (n/2-cnt2)) printf("%lld\n",(n/2-cnt2));
		else printf("%d\n",cnt1 + 2*(n/2-cnt2-cnt1));
	} else if(cnt1 < cnt2) {
		int len = st.size();
		for(int it = 0; it != len; it++) {
			ll tmp = sqrt(st[it]);
			ll MIN = min(st[it]-tmp*tmp,(tmp+1)*(tmp+1)-st[it]);
			vs.push_back(MIN);
		}
		sort(vs.begin(), vs.end());
		for(int i = 0; i < (cnt2-cnt1)/2; i ++) {
			ans += vs[i];
		}
		printf("%lld\n",ans);
	} else printf("0\n");
	return 0;
}