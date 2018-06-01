#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[11], b[11];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> a[i],mp[a[i]]++;
	for(int i = 0; i < m; i ++) cin >> b[i];
	sort(a,a+n);
	sort(b,b+m);
	for(int i = 0; i < m; i ++) {
		if(mp.count(b[i])) return 0*printf("%d\n",b[i]);
	}
	printf("%d%d",min(a[0],b[0]),max(a[0],b[0]));
	return 0;
}