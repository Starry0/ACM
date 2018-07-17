#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, k, a[N], x;
struct Nod{
	int id, num;
}e[N];
bool cmp(Nod a, Nod b) {
	return a.num > b.num;
}
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> x;	
		e[i].id = i;
		e[i].num = x;
	}
	sort(e+1,e+1+n,cmp);
	int ans = 0;
	for(int i = 1; i <= k; i ++) {
		a[i] = e[i].id;
		ans += e[i].num;
	}
	printf("%d\n",ans);
	if(k==1) return 0*printf("%d\n",n);
	sort(a+1,a+1+k);
	for(int i = 1; i < k; i ++) {
		printf("%d ",a[i]-a[i-1]);
	}
	printf("%d\n",n-a[k-1]);
	return 0;
}