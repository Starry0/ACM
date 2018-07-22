#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const double PI = acos(-1);
struct Point{
	double x, y;
}p[55];

double dis(Point a, Point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double ang(Point a, Point b, Point c) {
	double x1 = dis(a,b);
	double x2 = dis(c,b);
	double x3 = dis(a,c);
	return acos((x1*x1+x2*x2-x3*x3)/(2*x1*x2));
}
int main() {
	int t, n;
	cin >>t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n;
		for(int i = 0; i <= n; i ++) {
			cin >> p[i].x >> p[i].y;
		}
		double ans = 0;
		for(int i = 0; i < n; i ++) {
			ans += dis(p[n],p[i])*(PI-ang(p[(i-1+n)%n], p[i], p[(i+1+n)%n]));
		}
		printf("Case #%d: %.3lf\n",ca,ans);
	}
	return 0;
}