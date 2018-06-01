#include <stdio.h>
int main()
{
    int n, m;
	scanf("%d %d", &m, &n);
	int ans = 1;
	for(int i = 1; i <= n; i ++) {
		ans *= m;
	}
	printf("%d\n",ans);
    return 0;
}
