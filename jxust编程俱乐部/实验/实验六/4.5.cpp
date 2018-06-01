#include <stdio.h>
int main() {
    double sum = 0, x = 2, y = 1;
	for(int i = 1; i <= 20; i ++) {
		sum += x / y;
		x = x + y;
		y = x - y;
	}
	printf("%.12lf", sum);
    return 0;
}
