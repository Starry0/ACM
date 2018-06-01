#include <bits/stdc++.h>
using namespace std;
map<string, int> mp, mp1;
int main() {
	int t;
	string s;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			cin >> s;
			if(mp1.count(s)) continue;
			else mp1[s]++;
			sort(s.begin(), s.end());
			mp[s]++;
		}
		cin >> t;
		while(t--) {
			cin >> s;
			int ans = 0;
			if(mp1.count(s)) ans--;
			sort(s.begin(), s.end());
			ans += mp[s] ;
			printf("%d\n",ans);
		}
		mp.clear();
		mp1.clear();
	}
	return 0;
}