#include <stdio.h>
#include <math.h>

double min(double x, double y) { return x>y?y:x;}
double x[4], y[4];

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double getArea(double a, double b, double c) {
	double p = (a+b+c)/2.0;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main() {
	for(int i = 0; i < 4; i ++) scanf("%lf%lf",&x[i], &y[i]);
	double l1, l2, l3, l4, l5, l6;
	l1 = dist(x[0],y[0],x[1],y[1]);
	l2 = dist(x[1],y[1],x[2],y[2]);
	l3 = dist(x[2],y[2],x[3],y[3]);
	l4 = dist(x[3],y[3],x[0],y[0]);
	l5 = dist(x[0],y[0],x[2],y[2]);
	l6 = dist(x[1],y[1],x[3],y[3]);
	double area1 = getArea(l1,l2,l5)+getArea(l3,l4,l5);
	double area2 = getArea(l1,l4,l6)+getArea(l2,l3,l6);
	printf("%.3lf\n",min(area1,area2));
	return 0;
}