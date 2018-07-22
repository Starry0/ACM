#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
double x,y,gx,gy,xa,xb,xc,ya,yb,yc;
double ans1[4], ans2[4];
double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
	double x, y, gx, gy, x1, y1, r1, x2, y2, r2;
	cin >> x >> y >> gx >> gy >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double xx1 = dis(x,y,x2,y2);
	double xx2 = dis(gx,gy,x2,y2);
	double ans1 = sqrt(xx1*xx1-r2*r2);
	double ans2 = sqrt(xx2*xx2-r2*r2);
	double xx3 = dis(x,y,gx,gy);
	double a1 = acos(r2/xx1);
	double a2 = acos(r2/xx2);
	double a3 = acos((xx1*xx1+xx2*xx2-xx3*xx3)/(2*xx1*xx2));
	double ans3 = (a3-a2-a1)*r2;
	printf("%.10f\n",ans1+ans2+ans3);
	return 0;
}