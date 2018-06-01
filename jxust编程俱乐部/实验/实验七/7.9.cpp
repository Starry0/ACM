#include <stdio.h>
#include <string.h>
char str[7][1010];
int main(){
	int Max = -1, k = 0;
	for(int i = 0; i < 6; i ++) {
		scanf("%s", str[i]);
		if(strlen(str[i]) < Max) {
			Max = strlen(str[i]);
			k = i;
		}
	}
	printf("%s\n",str[k]);
	return 0;
}