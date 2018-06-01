#include <bits/stdc++.h>
using namespace std;
int a[11] = {1,0,0,0,1,0,1,0,2,1};
int main() {
	int k;
	cin >> k;
	if(k > 36) printf("-1\n");
	else{
		if(k <= 18) {
			for(int i = 0; i < k; i ++) printf("4");
			printf("\n");
		}else{
			for(int i = 0; i < k/2; i ++) printf("8");
			if(k&1)printf("4");
			printf("\n");
		}
	}
	return 0;
}