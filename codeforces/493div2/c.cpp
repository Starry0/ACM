#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5+10;
char str[N];
int main() {
	ll n, x, y, ans = 0, tmp = 0;
	cin >> n >> x >> y;
	cin >> str+1;
	for(int i = 1; i <= n; i ++) {
		if(str[i] == '0') {
			tmp++;
			while(str[i] == '0' && i <= n)i++;
		}
	}
	//cout << tmp << endl;
	if(tmp == 0) return 0*printf("0\n");
	if(x >= y) {
		cout << y*tmp << endl;
	} else {
		cout << x*(tmp-1)+y << endl;
	}
	return 0;
}
