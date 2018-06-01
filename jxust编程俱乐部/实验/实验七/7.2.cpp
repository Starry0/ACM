#include <stdio.h>
int main(){
	int a[11], MAX = -1, sum = 0;
	for(int i = 0; i < 10; i ++) {
		scanf("%d", &a[i]);
		if(MAX < a[i]) MAX = a[i];
		sum += a[i];
	}
	int ans = 0;
	for(int i = 0; i < 10; i ++) {
		if(a[i]*10 < sum) ans++;
	}
	printf("%d %.2lf %d\n",MAX, 1.0*sum/10, ans);
	return 0;
}