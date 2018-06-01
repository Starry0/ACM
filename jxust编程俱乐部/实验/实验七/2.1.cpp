#include <stdio.h>

int main(){
	int Min = 100000, MAX = -1, sum = 0, x;
	for(int i = 0; i < 10; i ++) {
		scanf("%d",&x);
		sum += x;
		if(x > MAX) MAX = x;
		if(x < Min) Min = x;
	}
	
	printf("%.0lf\n",1.0*(sum-MAX-Min)/8);
	return 0;
}