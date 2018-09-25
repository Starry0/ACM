#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 1e5+10;
ull c[MAX], c1[MAX];
int n, q, op, pos;
ull x;
void update(int x, ull y){
    while(x < MAX){
        c[x] += y;
        x += lowbit(x);
    }
}
ull query(int x){
    ull sum = 0;
    while(x > 0){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
void update1(int x, ull y){
    while(x < MAX){
        c1[x] += y;
        x += lowbit(x);
    }
}
ull query1(int x){
    ull sum = 0;
    while(x > 0){
        sum += c1[x];
        x -= lowbit(x);
    }
    return sum;
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &x);
		update(i,1LL*(n-i+1)*x);
		update1(i, x);
	}
	// for(int i = 1; i <= n; i++) printf("%lld ",query(i)-query(i-1));printf("\n");
	// for(int i = 1; i <= n; i++) printf("%lld ",query1(i)-query1(i-1));printf("\n");
	while(q--) {
		int l, r;
		scanf("%d%d%d",&op,&l,&r);
		if(op == 1) {
			ull ans1 = query(r)-query(l-1);
			ull ans2 = (n-r)*(query1(r)-query1(l-1));
			printf("%lld\n",ans1-ans2);
		} else {
			ull tmp = query1(l)-query1(l-1);
			update(l,1LL*(n-l+1)*(r-tmp));
			update1(l,1LL*(r-tmp));
		}
	}
	return 0;
}