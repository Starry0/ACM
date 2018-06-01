#include <stdio.h>

int main(){
	int x = 0, x1 = 0;
	for(int i = 1; i <= 4; i ++) {
		for(int j = 1; j <= 4; j ++) {
			int y;
			scanf("%d", &y);
			if(i == j) x += y;
			if(i + j == 5) x1 += y;
		}
	}
	printf("%d %d\n",x,x1);
	return 0;
}