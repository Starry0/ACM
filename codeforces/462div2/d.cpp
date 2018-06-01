/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vs;

int main() {
	ll p, k;
	cin >> p >> k;
	while(1){
		ll cnt = p+k,b=1;
		if(cnt>0){
			b += -cnt/k;
			cnt = p+ b*k;
			//printf("%lld %lld %lld\n",cnt,k,b);
			//break;
		}
		if(cnt<0){
			b += abs(cnt)/k+1;
			cnt =p+ k*b;
		}
		//printf("%lld %lld %lld\n",p,k,b);
		vs.push_back(cnt);
		if(cnt > 0 && cnt < k) break;
		p = b;
	}
	ll len = vs.size();
	cout << len << endl;
	for(int i = 0; i < len; i ++) {
		cout << vs[i] << ' ' ;
	}
	cout << endl;
	return 0;
}
*/

//化简得 0 <= k*An+A(n-1) < k  A0 = pair
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2020;
ll a[N], ans[N], k, p;
ll get(ll b, int i) {
	ans[i] = ((b%k)+k)%k;
	return (ans[i]-b)/k;
}
int main() {
	cin >> p >> k;
	a[0] = p;
	for(int i = 1; i < N; i ++) {
		a[i] = get(a[i-1],i);
		if(!a[i]) {
			cout << i << endl;
			for(int j = 1; j <= i; j ++) 
				printf("%lld%c",ans[j],j==i?'\n':' ');
			break;
		}
	}
	return 0;
}