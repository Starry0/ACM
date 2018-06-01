#include <bits/stdc++.h>
using namespace std;
int a[110], b[110];
int main() {
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int MIN = 0, MAX = 0;
	for(int i = 0; i < n-1; i ++) {
		int index = 0, M = -1;
		for(int j = 0; j < n-i; j ++) {
			if(a[j]+a[(j+1)%(n-i)] > M) {
				index = j;
				M = a[j] + a[(j+1)%n];
			}
		}
		MAX += M;
		if(index == n-1-i) a[0] = M;
		else{
			// printf("-=-=-=-\n");
			a[index] = M;
			for(int j = index+1; j < n-i-1; j ++) a[j] = a[j+1];
		}
		// for(int j = 0; j < n; j ++) printf("%d%c",a[j],(j==n-1?'\n':' '));
	}
	for(int i = 0; i < n-1; i ++) {
		int index = 0, M = 3000;
		for(int j = 0; j < n-i; j ++) {
			if(b[j]+b[(j+1)%(n-i)] < M) {
				index = j;
				M = b[j] + b[(j+1)%n];
			}
		}
		MIN += M;
		if(index == n-1-i) b[0] = M;
		else{
			b[index] = M;
			for(int j = index+1; j < n-i-1; j ++) b[j] = b[j+1];
		}
	}
	printf("%d\n%d\n",MIN,MAX);
	return 0;
}
