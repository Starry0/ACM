#include <stdio.h>

int main(){
	int n, ans = 0, num;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++){
		scanf("%d",&num);
		ans^=num;
	}
	if(ans)printf("A\n");
	else printf("B\n");
	return 0;
}