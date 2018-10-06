#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	int t, a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << max(a,b)*2+min(a,b) << endl;
	}
	return 0;
}