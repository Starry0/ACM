#include <stdio.h>
int main(){
	int h, f;
	scanf("%d %d", &h, &f);
	int y = (f - 2 * h) / 2;
	printf("%d %d\n",h-y, y);
	return 0;
}