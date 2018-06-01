#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010];
int main(){
	int row, clo, Max = -1, x;
	for(int i = 1; i <= 4; i ++) {
		for(int j = 1; j <= 5; j ++) {
			scanf("%d", &x);
			if(x > Max) {
				Max = x;
				row =i;
				clo = j;
			}
		}
	}
	printf("%d row=%d col=%d\n",Max,row,clo);
	return 0;
}