#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
	int n, l, x;
	scanf("%d %d", &n, &l);
	int Min = -1, MAx = -1;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		Min = max(Min, min(x, l-x));
		MAx = max(MAx, max(x, l-x));
	}
	printf("%d %d\n",Min, MAx);
	return 0;
}