#include <iostream>
#include <stdio.h>
#include <cstring>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 2e5+10;
int n, k;
ll a[N], sum[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		a[0] = 0;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
			a[i] += a[i-1];
		}
		for(int i = 1; i <= n-k+1; i ++) {
			sum[i] = a[i+k-1]-a[i-1];
		}
		ll MAX = -1e18;
		ll MAX1 = -1e18;
		for(int i = 1; i <= n-2*k+1; i ++) {
			if(sum[i] > MAX1) MAX1 = sum[i];
			if(MAX1 + sum[i+k] > MAX) MAX = MAX1 + sum[i+k];
		}
		cout << MAX << endl;
		memset(sum,0,sizeof(sum));
	}
	return 0;
}