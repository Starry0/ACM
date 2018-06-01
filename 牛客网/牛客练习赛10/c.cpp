#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char str[N];
int main() {
	int n, m, l, r;
	char ch1, ch2;
	cin >> n >> m;
	cin >> str+1;
	for(int i = 1; i <= m; i ++) {
		cin >> l >> r >> ch1 >> ch2;
		for(int j = l; j <= r; j ++) {
			if(str[j] == ch1) str[j] = ch2;
		}
	}
	cout << str+1 << endl;
	return 0;
}

