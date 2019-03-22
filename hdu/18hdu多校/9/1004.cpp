#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;

int main() {
	ll a1, a2, b1, b2, c1, c2, t;
	ll sum, up, down;
	cin >> t;
	while(t--) {
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		sum = a1+b1+c1;
		up = a2*(c1-b1)+b2*(a1-c1)+c2*(b1-a1);
		down = sum;
		if(up%sum == 0) printf("%lld\n",up/down);
		else {
			ll ans1 = up/__gcd(up,down); 
			down = down/__gcd(up,down);
			if((ans1<0&&down>0)||(ans1>0&&down<0)) printf("-");
			printf("%lld/%lld\n",abs(ans1),abs(down));
		}
	}
	return 0;
}