 #include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
const double Inf = 0.00000001;
struct Point{
	double x;
	double y;
	Point(){
		x = 0.0, y = 0.0;
	}
	Point(double x1, double y1){
		x = x1;
		y = y1;
	}
};
 Point circle(Point pt1, Point pt2, Point pt3, double &ra) {
        double x1 = pt1.x, x2 = pt2.x, x3 = pt3.x;
        double y1 = pt1.y, y2 = pt2.y, y3 = pt3.y;
        double a = x1 - x2;
        double b = y1 - y2;
        double c = x1 - x3;
        double d = y1 - y3;
        double e = ((x1 * x1 - x2 * x2) + (y1 * y1 - y2 * y2)) / 2.0;
        double f = ((x1 * x1 - x3 * x3) + (y1 * y1 - y3 * y3)) / 2.0;
        double det = b * c - a * d;
        if(fabs(det) < 1e-5) {
            ra = -1;
            return Point(0,0);
        }
        double x0 = -(d * e - b * f) / det;
        double y0 = -(a * f - c * e) / det;
        ra = hypot(x1 - x0, y1 - y0);
        return Point(x0, y0);
}
double dis(Point a, Point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main(){
	int t;
	cin >>t;
	Point a, b, c, d, e;
	double ra;
	while(t --) {
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		e = circle(a, b, c, ra);
		// printf("%.2lf %.2lf  %.2lf\n",e.x, e.y, ra);
		// printf("%.2lf %.2lf %.2lf\n",d.x,d,dis(e,d));
		if(dis(e,d) - ra > Inf) printf("Accepted\n");
		else printf("Rejected\n");
	}
	return 0;
}