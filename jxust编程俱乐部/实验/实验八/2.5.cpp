#include <stdio.h>
#include <math.h>
int main()
{
	int n, ans = 1, sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		ans *= i;
		sum += ans;
	}
	printf("%d\n", sum);
    return 0;
}

