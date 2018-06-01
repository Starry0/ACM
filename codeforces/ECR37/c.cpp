#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N];
char str[N];
int sum[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	cin >> str+1;
	for(int i = 1; i <= n; i ++) sum[i] = sum[i-1] + str[i]-'0';
	for(int i = 1; i <= n; i ++) {
		if(a[i]!=i&&abs(sum[a[i]-1]-sum[i-1])!=abs(a[i]-i)) {
			return 0*printf("NO\n");
		}
	}
	printf("YES\n");
	return 0;
}