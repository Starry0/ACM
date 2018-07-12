#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e4+10;
int a[N][101], b[110];
int main() {
	int w, s, x, y, tmp;
	cin >> w >>s;
	cin >> x >> y;
	for(int i = 1; i <= w; i ++) {
		for(int j = 1; j <= x; j ++) scanf("%d", &a[i][j]);
	}
	for(int i = 1; i <= s; i ++) {
		for(int j = 1; j <= x; j ++) {
			scanf("%d", &tmp);
			b[j] = max(b[j], tmp);
		}
	}
	for(int i = 1; i <= w; i ++) {
		for(int j = 1; j <= x; j ++) {
			a[i][j] = min(a[i][j], y-b[j]);
			printf("%d%c",a[i][j]," \n"[j==x]);
		}
	}
	return 0;
}