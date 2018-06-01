#include <bits/stdc++.h>
using namespace std;
int a[110];
map<int, int> mp;
int main() {
	int n, x;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		mp[a[i]] ++;
	}
	sort(a+1, a+1+n);
	if(mp.size() == 2 && a[n/2] != a[n/2+1]) printf("Yes\n%d %d\n",a[1],a[n]);
	else printf("No\n");
	return 0;
}