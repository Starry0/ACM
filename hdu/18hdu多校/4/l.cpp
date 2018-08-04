#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i =1 ; i <= n; i ++) cin >> a[i];
		printf("%d\n",int(sqrt(abs(a[1]-a[n]))));
	}
	return 0;
}