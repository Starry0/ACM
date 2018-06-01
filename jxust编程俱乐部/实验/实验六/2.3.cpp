#include <stdio.h>
int main() {
	for(int i = 1; i <= 9; i ++) {
		for(int j = 1; j <= i; j ++) {
			printf("%d*%d=%d%c",i,j,i*j,j==i?'\n':' ');
		}
	}
    return 0;
}
