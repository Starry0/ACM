#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int x[N], y[N];
double aa[11];
int main() {
	int t, n, a, b,c;
	scanf("%d", &t);
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			cin >> a >> b >> c;
			aa[i] = (-4.0*a*c-b*b)/(-4.0*a);
		}
		double MAX = aa[1];
		int index = 1;
		for(int i = 2; i <= n; i ++) {
			if(MAX < aa[i]) {
				MAX = aa[i];
				index = i;
			}
		}
		cout << index << endl;
	}
	return 0;
}