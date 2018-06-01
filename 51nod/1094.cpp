#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 10010;
ll a[N], sum[N];
ll n, k;
struct Nod{
	ll sum;
	int id;
	Nod(){
		sum = 0;
	}
}nod[N];
bool cmp(Nod a, Nod b) {
	if(a.sum != b.sum) return a.sum < b.sum;
	else a.id < b.id;
}
int bin(ll x) {
	int l = 1, r = n, pos = -1;
	while(l < r) {
		int m = (l + r) >> 1;
		if(nod[m].sum < x) {
			l = m + 1;
			pos = l;
		}
		else {
			r = m;
			pos = r;
		} 
	}
	return pos;
}
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i-1] + a[i];
		nod[i].sum = nod[i-1].sum + a[i];
		nod[i].id = i;
	}
	sort(nod+1, nod+1+n, cmp);
	bool flag = false;
	for(int i = 1; i <= n; i ++) {
		ll sumj = sum[i-1] + k;
		int index = bin(sumj);
		// printf("%lld %d %d\n",sumj,i,index );
		if(sum[nod[index].id] != sumj) continue;
		while(nod[index].sum == sumj && nod[index].id < i) index++;
		if(nod[index].id >= i && nod[index].sum == sumj) {
			printf("%d %d\n",i,nod[index].id);
			flag = true;
			break;
		}
	}
	if(!flag) printf("No Solution\n");
	return 0;
}