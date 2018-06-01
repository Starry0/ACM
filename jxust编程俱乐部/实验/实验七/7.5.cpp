#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a+1,a+1+n);
	printf("%d %d\n",a[k],a[n-k+1]);
	return 0;
}