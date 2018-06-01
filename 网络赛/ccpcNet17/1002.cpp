#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#define ll long long
using namespace std;
const int N = 22;
char str[N][N];
int a[N], b[N], q[N];
int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i ++) cin >> str[i]+1;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 1; i <= m; i ++) cin >> b[i];
		for(int i = 1; i <= q; i ++) cin >> q[i];
		
	}
	return 0;
}