#include <stdio.h>
#include <math.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	double x1 = (-b-sqrt(b*b-4*a*c))/(2*a);
	double x2 = (-b+sqrt(b*b-4*a*c))/(2*a);
	if(x1 > x2) {
		x1 = x1 + x2;
		x2 = x1 - x2;
		x1 = x1 - x2;
	}
	printf("%.2lf %.2lf\n", x1, x2);
	return 0;
}