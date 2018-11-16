#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main() {
	int a, b, flag = 0;
	scanf("%d:%d",&a,&b);
	for(int i = a; ; i--) {
		if(i < 0) i =  23;
		for(int j = (i==a)?b-1:59; j >= 0; j --) {
			if(i%10==j/10 && i/10==j%10) {
				printf("%d:%d\n",i,j);
				flag = 1;
				break;
			}
		}
		if(flag)break;
	}
	for(int i = a; ; i ++) {
		if(i == 24) i = 0;
		for(int j = (i==a)?b+1:0; j < 60; j ++) {
			if(i%10==j/10 && i/10==j%10) {
				return 0*printf("%d:%d\n",i,j);
			}
		}
	}
	return 0;
}