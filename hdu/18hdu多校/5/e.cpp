#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
const double PI = acos(-1);
int t, m;
double R, x, y, r;
double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
	cin >> t;
	while(t--) {
		cin >> m >> R;
		double sum = 2*PI*R;
		for(int i = 1; i <= m; i ++) {
			cin >> x >> y >> r;
			double cnt = dist(0,0,x,y);
			if(cnt <= R) {
				if(cnt + r == R) {
					sum += 2*PI*r;
				} else if(cnt + r > R) {
					
				}
			} else {
				if(cnt - r < R) {

				}
			}
		}
		printf("%.20lf\n",sum);
	}
	return 0;
}