#include <stdio.h>
#define PI 3.1415926535
int main(){
	double r;
	scanf("%lf", &r);
	double area = PI*r*r;
	double zh = 2*PI*r;
	printf("%.2lf %.2lf\n",area,zh);
	return 0;
}