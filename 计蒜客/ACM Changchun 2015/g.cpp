#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
double x[N], y[N];
double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		double sumx = 0, sumy = 0;
		for(int i = 1; i <= n; i ++) {
			cin >> x[i] >> y[i];
			sumx += x[i];
			sumy += y[i];
		}
		double X = sumx/n, Y = sumy/n;
		double ans = dis(X,Y,x[1],y[1]);
		bool flag = true;
		for(int i = 2; i <= n; i ++) {
			double ans1 = dis(X,Y,x[i],y[i]);
			if(ans1 != ans) {
				flag = false;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}