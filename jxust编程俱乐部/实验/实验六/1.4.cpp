#include <stdio.h>
int main() {
	double sum = 0;
	for(int i = 2; i <= 100; i += 4) {
		sum += 1.0/i;
	}
	for(int i = 4; i <= 100; i += 4) {
		sum -= 1.0/i;
	}
	printf("%.3lf\n", sum);
	return 0;
}