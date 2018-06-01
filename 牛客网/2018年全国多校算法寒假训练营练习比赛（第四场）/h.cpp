#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[] = {1,2,3,4,5,6,7,8};
int main() {
	do{
		for(int i = 0; i < 8; i ++) {
			printf("%d%c",a[i],(i==7)?'\n':' ');
		}
	}while(next_permutation(a,a+8));
	return 0;
}