#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	string s = "jessie";
	sort(s.begin(), s.end());
	// cout << s << endl;
	while(t--) {
		string ss;
		cin >> ss;
		for(int i = 0; i < ss.length(); i ++) {
			if(ss[i] >='A' && ss[i] <= 'Z') ss[i] = ss[i] + 32;
		}
		// cout << ss << endl;
		sort(ss.begin(), ss.end());
		if(ss == s) printf("Good guy!\n");
		else printf("Dare you say that again?\n");
	}
	return 0;
}