#include <stdio.h>
#include <math.h>
double a, b, c, d;
double fun(double x) {
	return a*x*x*x+b*x*x+c*x+d;
}
double fun1(double x) {
	return 3*a*x*x+2*b*x+c;
}
int main() {
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	double x = 1, xo;
	do{
		xo = x;
		x = xo - fun(xo)/fun1(xo);
	}while(fabs(x-xo) >= 1e-15);
	printf("%.3lf\n", x);
    return 0;
}
