#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+10;
map<string,int> mp1, mp2;
set<string> st;
string s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n;
	string ss;
	for(int i = 1; i <= n; i ++) {
		cin >> s[i];
		st.clear();
		int len = s[i].length();
		for(int j = 0; j < len; j ++) {
			for(int k = 1; k <= len-j; k ++) {
				ss = s[i].substr(j,k);
				st.insert(ss);
			}
		}
		for(auto tmp : st) {
			mp1[tmp]++;
			mp2[tmp] = i;
			//cout << tmp << endl;
		}
	}
	cin >> q;
	while(q--) {
		cin >> ss;
		if(mp1.count(ss)) {
			cout << mp1[ss] << ' ' << s[mp2[ss]] << endl;;
		} else cout << "0 -\n";
	}
	return 0;
}