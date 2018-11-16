#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	for(int i = 123; i <= 333; i ++) {
		int b = 2*i, c = 3*i;
		memset(a,0,sizeof(a));
		a[i%10] = a[i/100] = a[i/10%10] = 1;
		a[b%10] = a[b/100] = a[b/10%10] = 1;
		a[c%10] = a[c/100] = a[c/10%10] = 1;
		bool flag = 1;
		for(int j = 1; j < 10; j ++) if(!a[j]) flag = 0;
		if(flag) printf("%d %d %d\n",i,b,c);
	}
	return 0;
}