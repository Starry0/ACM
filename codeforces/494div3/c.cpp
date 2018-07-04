#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5010;
int a[N], sum[N];

int main() {
	int n, k, x;
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i ++) {
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	double MAX = 0;
	for(int i = 1; i <= n-k+1; i ++) {
		for(int j = k+i-1; j <= n; j ++) {
			int S = sum[j] - sum[i-1];
			MAX = max(MAX, 1.0*S/(j-i+1));
		}
	}
	printf("%.15lf",MAX);
	return 0;
}