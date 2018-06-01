#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
	double pi = acos(-1);
	double gx, gy, gr, wx, wy, wr;
	while(scanf("%lf %lf %lf %lf %lf %lf", &gx, &gy, &gr, &wx, &wy, &wr) != EOF) {
		double dd = dis(gx, gy, wx, wy);
		if(dd >= (wr + gr) || wr == 0 || gr == 0) printf("0.000\n");
		else if(dd <= fabs(wr - gr)) {
			double rr = min(wr, gr);
			printf("%.3f\n",rr*rr*pi);
		} else {
			double a1 = acos((gr*gr + dd*dd - wr*wr) / (2*gr*dd));
			double a2 = acos((wr*wr + dd*dd - gr*gr) / (2*wr*dd));
			double area1 = (sin(a1*2)*gr*gr+sin(a2*2)*wr*wr)/2;
			double area2 = gr*gr*a1 + wr*wr*a2;
			printf("%.3f\n",(area2-area1));
		}
	}
	return 0;
}