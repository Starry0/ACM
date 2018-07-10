#include <bits/stdc++.h>
using namespace std;
const int N = 35;
char str[N][N];
int vis[N][N];
char s[N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, 
	dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, h, w, t;
int ok() {
	int len = strlen(s);
	if(len == 1) return 1;
	for(int i = 0; i <= len/2; i ++) {
		if(s[i] != s[len-1-i]) return 2;
	}
	return 3;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d", &n, &h, &w);
		for(int i = 1; i <= h; i ++) scanf("%s", str[i]+1);
		bool flag = false, flag1 = false;
		bool flag2 = false;
		while(n--) {
			scanf("%s", s);
			int ans = 0, len;
			int ok1 = ok();
			if(ok1 == 1) len = 1;
			else if(ok1 == 2) len = 8;
			else len = 4;
			for(int i = 1; i <= h; i ++) {
				for(int j = 1; j <= w; j ++) {
					for(int k = 0; k < len; k ++) {
						int nx = i, ny = j;
						bool flag1 = true;
						// if(i==3&&j==5&&l==5) printf("%d\n",k);
						for(int l = 0; s[l]; l ++) {
							// if(i==7&&j==2&&k==2) printf("%c %c\n",str[nx][ny],s[l]);
							if(str[nx][ny] != s[l] || nx > h || ny > w) {
								flag1 = false;
								break;
							}
							nx = nx + dx[k], ny = ny + dy[k];
						}
						if(flag1) {
							ans++;
							nx = i, ny = j;
							for(int l = 0; s[l]; l ++) {
								vis[nx][ny]++;
								nx = nx + dx[k], ny = ny + dy[k];
							}
						}
					}
				}
			}
			// printf("ans:%d\n",ans);
			if(ans > 1) {
				flag = true;
			} else if(ans == 0) {
				flag2 = true;
			}
		}
		if(flag2) {
			printf("no solution\n");
			continue;
		}
		for(int i = 1; i <= h; i ++) {
			for(int j = 1; j <= w; j ++) {
				if(vis[i][j] == 0) {
					flag1 = true;
				}
			}
		}
		if(flag) {
			printf("ambiguous\n");
		} else if(!flag1){
 			printf("empty solution\n");
		} else {
			for(int i = 1; i <= h; i ++) {
				for(int j = 1; j <= w; j ++) {
					if(vis[i][j] == 0) printf("%c",str[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

// 4
// 10 7 8
// ********
// TA*****L
// IMELB*RP
// MGOA*RR*
// BIP**IE*
// UC*TZ*C*
// S*HEMS**

// BAPC
// PROBLEM
// SUBMIT
// CORRECT
// PRIZE

// ALGORITHMS