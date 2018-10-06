#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
char s[110];
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> s;
		int ans = 0;
		for(int i = 0; s[i]; i ++) {
			if(s[i] == 'H') ans += 1;
			else if(s[i] == 'O') ans += 16;
			else if(s[i] == 'C') ans += 12;
		}
		cout << ans << endl;
	}
	return 0;
}