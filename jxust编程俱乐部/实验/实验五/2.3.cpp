#include <stdio.h>
#include <math.h>
int main()
{
	double x;
	scanf("%lf", &x);
	if(x < -1) printf("%.6lf\n",x*x*x-1);
	else if(x <= 1) printf("%.6lf\n", -3*x+1);
	else if(x <= 10) printf("%.6lf\n", 3*exp(2*x-1)+5);
	else printf("%.6lf\n", 5*x+3*log10(2*x*x-1)-13);
    return 0;
}
