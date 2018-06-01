#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, tmp1 = 1, tmp2 = 1, tmp3 = 1;
	cin >> n;
	for(int i = 0; i <= n-3; i ++) {		
		tmp3 = (tmp1 + tmp2) % 10007;
		tmp1 = tmp2;
		tmp2 = tmp3;
	}
	printf("%d\n", tmp3);
	return 0;
}