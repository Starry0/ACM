#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	ll n;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		ll y1 = (-3-sqrt(9-12*(1-n)))/6;
		ll y2 = (-3+sqrt(9-12*(1-n)))/6;
		// printf("%lld %lld\n",y1,y2);
		if(y1 > 0 && y1*y1+y1*(y1+1)+(y1+1)*(y1+1)==n) printf("YES\n");
		else if(y2 > 0 &&  y2*y2+y2*(y2+1)+(y2+1)*(y2+1)==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}