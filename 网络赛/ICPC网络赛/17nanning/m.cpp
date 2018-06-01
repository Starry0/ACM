#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int a[N];
int main() {
	int n, num = 0, m = 0;
	double aa;
	char c;
	scanf("%d %lf", &n, &aa);
	getchar();
	while((c = getchar()) != EOF) {
		int ans = c - '0';
		while((c = getchar()) != '\n') {
			if(c >= '0' && c <= '9') {
				ans = ans * 10 + c - '0';
			}else {
				a[m] += 1 << (ans - 1);
				ans = 0;
			}
		}
		a[m] += 1 << (ans - 1);
		m ++;
	}
	int ma = ceil(aa*m);
	int cnt = 0;
	for(int i = 1; i < (1<<n); i ++) {
		int num = 0;
		for(int j = 0; j < m; j ++) {
			if((i & a[j]) == i) num ++;
		}
		if(num >= ma) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}