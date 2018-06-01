#include <stdio.h>
int main() {
	int n, sum = 0, x;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", &x);
		sum += x;
	}
	printf("%.3lf\n",1.0*sum/n);
	return 0;
}