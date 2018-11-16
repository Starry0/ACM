#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, sum = 0, now = 0;
	cin >> k;
	for(int i = 1; ; i ++) {
		for(int j = 1; j <= i; j ++) {
			sum += i;
			now ++;
			if(now == k) return 0*printf("%d\n",sum);
		}
	}
	return 0;
}