#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[55];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s",s);
		map<char,int> mp;
		int ans = 0, cnt = 0;
		for(int i = 0; s[i]; i ++) {
			ans += cnt;
			mp[s[i]]++;
			if(mp[s[i]] <= 2) cnt++;
		}
		printf("%d\n",ans);
	}
	return 0;
}