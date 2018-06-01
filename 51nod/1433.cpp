#include <bits/stdc++.h>
using namespace std;
int a[6];
int main() {
	int n, x, sum = 0;
	cin >> n;
	while(n--) {
		cin >> x;
		a[x] ++;
		sum += x;
	}
	if(a[0] == 0) printf("-1\n");
	else if(a[5] < 9) printf("0\n");
	else {
		a[5] = a[5] - a[5] % 9;
		for(int i = 1; i <= a[5]; i ++) printf("5");
		for(int i = 1; i <= a[0]; i ++) printf("0");
		printf("\n");
	}
	return 0;
}