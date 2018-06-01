#include <bits/stdc++.h>
using namespace std;
int a[7];
int main() {
	int sum = 0;
	for(int i = 0; i < 6; i ++) cin >> a[i], sum += a[i];
	if(sum&1) return 0*printf("NO\n");
	for(int i = 0; i < 6; i ++) {
		for(int j = i+1; j < 6; j++) {
			for(int k = j+1; k < 6; k ++) {
				if(a[i]+a[j]+a[k] == sum/2) return 0*printf("YES\n");
			}
		}
	}
	printf("NO\n");
	return 0;
}