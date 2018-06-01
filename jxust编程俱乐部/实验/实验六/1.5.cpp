#include <stdio.h>
int main() {
	int n, sum = 0, x;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		if(x&1) sum += x;
	}
	printf("%d\n", sum);
	return 0;
}