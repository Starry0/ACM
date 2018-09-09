#include <bits/stdc++.h>
using namespace std;
const int N = 120;
char s[N][N];
int main() {
	int n, m, MAXX,MINX,MAXY,MINY;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> s[i]+1;
	MAXY = MAXX = -1; MINY = MINX = N;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] == 'B') {
				MAXX = max(MAXX, i);
				MINX = min(MINX, i);
				MAXY = max(MAXY, j);
				MINY = min(MINY, j);
			}
		}
	}
	// printf("%d %d %d %d\n",MINX,MAXX, MINY,MAXY);
	printf("%d %d\n",(MAXX+MINX)/2,(MAXY+MINY)/2);
	return 0;
}