#include <stdio.h>
int main(){
	int a, b, h;
	scanf("%d %d %d", &a, &b, &h);
	printf("%.2lf",1.0*(a+b)*h/2);
	return 0;
}