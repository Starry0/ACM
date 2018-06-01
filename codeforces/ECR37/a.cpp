#include <bits/stdc++.h>
using namespace std;
int x[220];
int main() {
	int t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= k; i ++) cin >> x[i];
		int MAX = x[1];
		for(int i = 2; i <= k; i ++) 
			MAX = max(MAX,(x[i]-x[i-1])/2+1);
		MAX = max(MAX,n-x[k]+1);
		cout << MAX << endl;
	}
	return 0;
}