#include <iostream>
#include <stdio.h>
#define ll long long
#include <algorithm>
using namespace std;
const int N = 1e5+10;
struct Nod {
	ll c,l;
	double a;
}nod[33];
ll n, l, cost[33];
bool cmp(Nod a, Nod b) {
	if(a.a != b.a) return a.a < b.a;
	else return a.l > b.l;
}
int main() {
	cin >> n >> l;
	for(ll i = 1; i <= n; i ++) {
		cin >> nod[i].c;
		nod[i].l = (1<<(i-1));
		nod[i].a = 1.0*nod[i].c/nod[i].l;
	}
	sort(nod+1,nod+1+n,cmp);
	ll sum = 0, tmp;
	for(ll i = 1; i <= n; i ++) {
		ll tmp = l/nod[i].l;
		l -= tmp*nod[i].l;
		sum += tmp*nod[i].c;
		if(l > 0) {
			cost[i] = sum + nod[i].c;
		} else {
			cost[i] = sum;
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(sum > cost[i]) {
			sum = cost[i];
		}
	}
	cout << sum << endl;
	return 0;
}