#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5+10;
int a[N], b[N], c[N], d[N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int n, x;
	cin >> n;
	string s;
	for(int i = 1; i <= n; i ++) {
		cin >> s >> x;
		if(s == "11")  a[++a[0]] = x;
		else if(s == "10") b[++b[0]] = x;
		else if(s == "01") c[++c[0]] = x;
		else d[++d[0]] = x;
	}
	sort(a+1,a+1+a[0],cmp);
	sort(b+1,b+1+b[0],cmp);
	sort(c+1,c+1+c[0],cmp);
	ll ans = 0;
	for(int i = 1; i <= a[0]; i ++) ans += 1LL*a[i];
	for(int i = 1; i <= min(b[0],c[0]); i ++) ans += 1LL*(b[i]+c[i]);
	for(int i = min(b[0],c[0])+1; i <= max(b[0],c[0]); i ++) d[++d[0]] = max(b[i],c[i]);
	sort(d+1,d+1+d[0],cmp);
	for(int i = 1; i <= min(a[0],d[0]); i ++) ans += 1LL*d[i];
	printf("%lld\n",ans);
	return 0;
}