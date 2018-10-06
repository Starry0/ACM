#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	int t, n, m, k;
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ca ++) {
		scanf("%d%d%d", &n, &m, &k);
		double ans = 0;
		for(int i = 0; i < k; i ++) {
			ans += (1.0*(n-i)/(m-i));
		}
		printf("Case #%d: %lf\n",ca,ans);
	}
	return 0;
}