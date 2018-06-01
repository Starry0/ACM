#include <bits/stdc++.h>
using namespace std;
int a[400];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	int MIN = 360;
	for(int i = 0; i < n; i ++) {
		int sum = 0;
		for(int j = i; j < n; j ++) {
			sum += a[j];
			MIN = min(MIN, abs(sum-(360-sum)));
		}
	}
	cout << MIN << endl;
	return 0;
}