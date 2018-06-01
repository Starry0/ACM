#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N*5], dp[N*5];
int main() {
	int n, num = 0;
	while(scanf("%d", &n) != EOF) {
		if(n >= 10000) {
			for(int i = 0; i < 5; i ++) a[num++] = n - 10000;
		} else if(n >= 0) a[num++] = n;
	}
	for(int i = 0; i <= N*5; i ++) dp[i] = 1000000;
	for(int i = 0; i < num; i ++) {
		*upper_bound(dp, dp+num, a[i]) = a[i];
	}
	cout << lower_bound(dp,dp+num,1000000)-dp << endl ;
	return 0;
}