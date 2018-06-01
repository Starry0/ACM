#include <stdio.h>
int main(){
	int cnt = 0;
	for(int i = 1; i <= 20; i ++) {
		for(int j = 1; j <= 20; j ++) {
			for(int k = 1; k <= 10; k ++) {
				if(i+j+k==20 && i+j*5+k*10==100) 
					cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	cnt = 1;
	for(int i = 1; i <= 20; i ++) {
		for(int j = 1; j <= 20; j ++) {
			for(int k = 1; k <= 10; k ++) {
				if(i+j+k==20 && i+j*5+k*10==100) 
					printf("Case #%d: %d %d %d\n",cnt++,i,j,k);
			}
		}
	}
	return 0;
}