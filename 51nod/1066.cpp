#include <stdio.h>
using namespace std;

int main(){
	int t, n, k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		if(n%(k+1)==0) printf("B\n");
		else printf("A\n");
	}
	return 0;
}