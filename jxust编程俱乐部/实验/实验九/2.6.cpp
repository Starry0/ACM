#include <stdio.h>
int main(){
	char str[100], str1[10];
	scanf("%s %s",str, str1);
	int ans = 0;
	for(int i = 0; str[i]; i ++) {
		if(str[i] == str1[0]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}