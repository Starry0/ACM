#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6+10;
double sum, MIN, x;
int n;
int main() {
	scanf("%lf %d %lf",&sum,&n,&MIN);
	double ans = sum;
	for(int i = 1; i < n; i ++) {
		scanf("%lf", &x);
		if(i == 1) ans = (sum/MIN)*(x-MIN);
		if(MIN > x) MIN = x;
		else {
			ans = max(ans,(sum/MIN)*(x-MIN));
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}