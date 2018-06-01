#include <stdio.h>
int main() {
	int sum = 0, ans = 1;
	for(int i = 1; i <= 10; i ++) {
		ans *= i;
		sum += ans;
	}
	printf("%d\n", sum);
	return 0;
}