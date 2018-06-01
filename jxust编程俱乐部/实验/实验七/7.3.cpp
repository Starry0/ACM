#include <stdio.h>
int main(){
	int a[11], MAX = -1, sum = 0;
	for(int i = 0; i < 10; i ++) {
		scanf("%d", &a[i]);
	}
	for(int i = 9; i >= 0; i --) {
		printf("%d%c", a[i],i==0?'\n':' ');
	}
	return 0;
}