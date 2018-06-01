#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
string s[N], ss;
ll count(string s) {
	ll ans = 0, tmp = 0;
	for(int i = 0; i < s.length(); i ++) {
		if(s[i] == 's') tmp++;
		else if(s[i] == 'h') ans += tmp;
	}
	return ans;
}
bool cmp(string &a, string &b) {
	return count(a+b) > count(b+a);
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> s[i];
	sort(s,s+n,cmp);
	for(int i = 0; i < n; i ++) ss += s[i];
	cout << count(ss) <<endl;
	return 0;
}