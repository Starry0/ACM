#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string,int> mp;
int main() {
	int n;
	cin >> n;
	string s;
	while(n--) {
		cin >> s;
		if(mp.count(s)) printf("YES\n");
		else printf("NO\n");
		mp[s] ++;
	}
	return 0;
}