#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
char s[N], t[N];

int main() {
	cin >> s >> t;
	int lens = strlen(s), lent = strlen(t);
	int i = lens-1, j = lent-1;
	int ans = 0;
	while(s[i] == t[j] && i >= 0 && j >= 0) {
		i--;j--;
		ans += 2;
	}
	cout << lens+lent-ans << endl;
	return 0;
}