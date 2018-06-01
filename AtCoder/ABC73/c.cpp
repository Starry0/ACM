#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
	int n, x;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		mp[x] ++;
	}
	int ans = 0;
	map<int,int>::iterator it = mp.begin();
	for(; it!= mp.end(); it++) {
		if((*it).second % 2 == 1) ans ++;
	}
	printf("%d\n",ans);
	return 0;
}