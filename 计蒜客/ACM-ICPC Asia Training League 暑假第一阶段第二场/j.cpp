#include <bits/stdc++.h>
using namespace std;
const int N = 300;
char str[N][N];
char s[100100];
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
int main() {
	int t;
	cin >> t;
	printf("%d\n",t);
	while(t--) {
		cin >> s;
		memset(str,0, sizeof(str));
		int x = 150, y = 150;
		int last = 0;
		str[x][y] = '.';
		for(int i = 0; s[i]; i ++) {
			if(s[i] == 'F') {
			} else if(s[i] == 'B') {
				last = (last+2)%4;
			} else if(s[i] == 'L') {
				last = (last+1)%4;
			} else if(s[i] == 'R') {
				last = (last-1+4)%4;
			}
			x += dx[last], y += dy[last];
			str[x][y] = '.';
		}
		int x1 = N, y1 = N, x2 = 0, y2 = 0;
		for(int i = 1; i < N; i ++) {
			for(int j = 1; j < N; j ++) {
				if(str[i][j] == '.') {
					x1 = min(x1, i);
					y1 = min(y1, j);
					x2 = max(x2, i);
					y2 = max(y2, j);
				}
			}
		}
		x1--;x2++;y2++;
		printf("%d %d\n",x2-x1+1,y2-y1+1);
		for(int i = x1; i <= x2; i ++) {
			for(int j = y1; j <= y2; j ++) {
				if(str[i][j] == '.') printf(".");
				else printf("#");
			}printf("\n");
		}
	}
	return 0;
}