#include <bits/stdc++.h>
using namespace std;
int n, a[6], i;

int main() {
	for(cin >> n; i < 6; i ++) cin >> a[i];
	cout << min((n+a[0]-1)/a[0]*a[1], min((n+a[2]-1)/a[2]*a[3],(n+a[4]-1)/a[4]*a[5])) << endl;
	return 0;
}