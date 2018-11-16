#include <bits/stdc++.h>
#define ll long long
using namespace std;

void exgcd(ll a, ll b,ll &d, ll &x, ll &y) {
    if(!b){
    	d = a;
        x = 1; y = 0;
    }else{
        exgcd(b, a%b, d, y, x);
        y -= x*(a/b);
    }
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll a, b, x, y, n, d;
		scanf("%lld%lld%lld",&n,&a,&b);
		exgcd(a,b,d,x,y);
		n++;
		if(n%d) {
			printf("0\n");
			continue;
		}
		a /= d; b /= d;
		x *= n/d; y *= n/d;
		ll xx = (x-(x/b)*b);
		ll yy = (y+(x/b)*a);
		if(xx <= 0) xx += b, yy -= a;
		// printf("%lld %lld\n",xx,yy );
		if(xx > n || yy <= 0) printf("0\n");
		else printf("%lld\n",min((n-xx)/b+((n-xx)%b?1:0),yy/a+((yy%a)?1:0)));
	}
	return 0;
}