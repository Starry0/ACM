#include <stdio.h>
#include <math.h>
int main(){
	int m;
	scanf("%d", &m);
	if(m < 2) return printf("No\n");
	for(int i = 2; i <= sqrt(m); i ++) {
		if(m % i == 0) return printf("No\n");
	}
	printf("Yes\n");
	return 0;
}