#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e3+10;
int a[N];
int main() {
	int t, n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		for(int j = i+1; j <= n; j ++) {
			if(a[j]-a[i] < 0) return 0*printf("no\n");
		}
	}
	printf("yes\n");
	return 0;
}