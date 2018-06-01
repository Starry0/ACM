#include <stdio.h>
int main() {
	double sum = 0;
	for(int i = 1; i <= 99; i += 2) {
		sum += 1.0/i;
	}
	printf("%.3lf\n", sum);
	return 0;
}