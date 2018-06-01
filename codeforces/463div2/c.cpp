#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int p[N];
int main() {
	int n, a, b, x, y;
	cin >> n >> a >> b;
	for(x = 0; x <= n; x ++) {
		int ans = n-x*a;
		if(ans < 0) break;
		if(ans >= 0 && ans%b==0) {
			y = ans/b;
			break;
		}
	}
	if(x*a > n) printf("-1\n");
	else{
		for(int i = 0; i < x; i ++) {
			p[i*a+1] = (i+1)*a;
			for(int j = i*a+2; j <= (i+1)*a; j ++) {
				p[j] = j-1;
			}
		}
		for(int i = 0; i < y; i ++) {
			p[a*x+i*b+1] = (i+1)*b+a*x;
			for(int j = x*a+i*b+2; j <= (i+1)*b+a*x; j ++) {
				p[j] = j-1;
			}
		}
		for(int i = 1; i <= n; i ++) {
			printf("%d ",p[i]);
		}
	}
	return 0;
}
