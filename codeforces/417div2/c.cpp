#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N], b[N], k, t, n, l, r, s, ans;

bool check(ll x ){
	for(int i =1; i <=n ; i ++){
		b[i] = a[i]+i*x;
	}
	sort(b+1,b+n+1);
	ans=0;
	for(int i = 1; i <=x; i ++){
		ans+=b[i];
	}
	if(ans>s)return false;
	else return true;
}

int main(){
	cin >> n >> s;
	for(int i = 1; i <= n; i ++)scanf("%lld",&a[i]);
	l = 1, r = n;
	while(l<=r){
		ll mid = (l+r)/2;
		if(check(mid)){
			k = mid;
			t = ans;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << k << " " << t << endl;
    return 0;
}
