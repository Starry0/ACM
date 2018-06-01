#include <bits/stdc++.h>
using namespace std;
char str[110];
int main() {
	int n, m;
	cin >> n >> m;
	cin >> str;
	while(m--) {
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;
		for(int i = l; i <= r; i ++) {
			if(str[i-1] == c1) str[i-1] = c2;
		}
	}
	cout << str << endl;
	return 0;
}