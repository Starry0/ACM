#include <stdio.h>
#include <math.h>
#define ll long long
int main() {
	double x;
	scanf("%lf", &x);
	double sum = 0;
	double xx = x,yy=1;
	for(int i = 2; ; i ++ ) {
		if(i&1) sum -= xx/yy;
		else sum += xx/yy;
		xx *= x;
		yy *= i;
		if(fabs(xx/yy) < 1e-9) break;
	}
	printf("%.8lf\n",sum + 1);
	return 0;
}

