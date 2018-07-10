#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
char str[N];
map<int,int> mp;
int main() {
	scanf("%s", str);
	int len = strlen(str);
	int ans = 0, tmp = 0;
	mp[0] = 1;
	for(int i = 0; i < len; i ++) {
		tmp += (str[i]-'0');
		tmp %= 3;
		if(mp[tmp]) {
			ans++;
			tmp = mp[1] = mp[2] = 0;
		} else mp[tmp]++;
	}
	cout << ans << endl;
	return 0;
}
