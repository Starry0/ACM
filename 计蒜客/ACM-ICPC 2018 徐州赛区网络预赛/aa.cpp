#include <bits/stdc++.h>
using namespace std;
int a[10];
bool ok() {
	for(int i = 0; i < 5; i ++) {
		if(a[i] == 0) {
			if(a[(i+1)%4]==3 || a[(i-1+4)%4]==3) return false;
		}
		if(a[i] == 1) {
			if(a[(i+1)%4]==2 || a[(i-1+4)%4]==2) return false;
		}
		if(a[i] == 2) {
			if(a[(i+1)%4]==1 || a[(i-1+4)%4]==1) return false;
		}
		if(a[i] == 3) {
			if(a[(i+1)%4]==0 || a[(i-1+4)%4]==0) return false;
		}
	}
	return true;
}
int main() {
	int ans = 0, ans1 = 0;
	for(int i = 0; i < 4; i ++) {
		for(int j = 0; j < 4; j ++) {
			for(int l = 0; l < 4; l ++) {
				for(int k = 0; k < 4; k ++) {
					for(int q = 0; q < 4; q ++) {
						ans1++;
						a[0] = i, a[1] = j, a[2] = l, a[3] = k, a[4] = q;
						if(ok()) printf("%d %d %d %d %d\n",i,j,l,k,q ), ans++;
					}
				}
			}
		}
	}
	printf("ans:%d %d\n",ans, ans1);
	return 0;
}