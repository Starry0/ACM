#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 1e6+100;
int w[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		w[x]++;
	}
	for(int i = 0; i < N; i ++) {
		if(w[i]) {
			ans += w[i]%2;
			w[i+1] += w[i]/2;
		}
	}
	cout << ans << endl;
	return 0;
}
