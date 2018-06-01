#include <stdio.h>
#include <math.h>
int a[100];
int main() {
	int sum = 0, k = 0;
	for(int i = 100; i <= 200; i ++) {
		bool flag = true;
		for(int j = 2; j <= sqrt(i); j ++) {
			if(i % j == 0) {
				flag = false;
				break;
			}
		}
		if(flag) {
			sum += i;
			a[k++] = i;
		}
	}
	printf("%d\n", sum);
	for(int i = 0; i < k; i ++) {
		printf("%d%c",a[i],i==k?'\n':' ');
	}
    return 0;
}
