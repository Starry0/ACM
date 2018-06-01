#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int N = 100010;
int ans[N];
int MAX, MAX1, l, r,ll,rr;
int main() {
	int k;
	scanf("%d",&k);
	r = k-1;
	for(int i = 0; i < k; i ++) scanf("%d",&ans[i]);
	for(int i = 0; i < k; i ++) {
		if(MAX1 >= 0) {
			MAX1 += ans[i];
			rr = i;
		}else {
			MAX1 = ans[i];
			ll = rr = i;
		}
		if(MAX1 > MAX || (MAX1 == 0 && r == k-1)) {
			MAX = MAX1;
			l = ll;
			r = rr;
		}
	}
	printf("%d %d %d\n",MAX,ans[l],ans[r]);
	return 0;
}