#include <stdio.h>

int main() {
	int a, n, sum = 0;
	scanf("%d %d",&a, &n);
	int cnt = a;
    for(int i = 1; i <= n; i ++) {
		sum += cnt;
		cnt = cnt*10 + a;
	}
	printf("%d\n",sum);
	return 0;
}
