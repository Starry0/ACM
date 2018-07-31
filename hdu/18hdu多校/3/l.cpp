#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char s[N][N];
int t, a, b, c;
int main() {
	cin >> t;
	while(t--) {
		memset(s,0,sizeof(s));
		cin >> a >> b >> c;
		for(int x = 1; x <= 2*c+1+2*b; x ++) {
			for(int y = 1; y <= 2*a+1+2*b; y ++) {
				if(x <= 2*b) {
					if(x+y-2*b-1 <=0) s[x][y] = '.';
					else if(x+y-2*a-2*b-2*c-3 >= 0) s[x][y] = '.';
					else if(x%2==1&&y%2==1) s[x][y] = '+';
					else if(x%2==1&&(y-(2*b-x+1)) <= 2*a) s[x][y] = '-';
					else if(x%2==0&&y%2==0) s[x][y] = '/';
					else if(x%2==0&&(y-(2*b-x+1)) <= 2*a) s[x][y] = '.';
					else if(x%2==1&&(y-(2*b-x+1)) > 2*a) s[x][y] = '.';
					else if(x%2==0&&(y-(2*b-x+1)) > 2*a) s[x][y] = '|';
				} else {
					if(x+y-2*a-2*b-2*c-3 >= 0) s[x][y] = '.';
					else if(x+y-2*b-1 <=0) s[x][y] = '.';
					else if(x%2==1&&y%2==1) s[x][y] = '+';
					else if(x%2==1&&y <= 2*a) s[x][y] = '-';
					else if(x%2==0&&y%2==1) s[x][y] = '|';
					else if(x%2==0&&y%2==0&&y <= 2*a) s[x][y] = '.';
					else if(x%2==1&&y>2*a)s[x][y] = '.';
					else if(x%2==0&&y>2*a)s[x][y] = '/';
				}
			}
		}
		for(int i = 1; i <= 2*c+1+2*b; i ++) {
			for(int j = 1; j <= 2*a+1+2*b; j ++) printf("%c",s[i][j]);
			printf("\n");
		}
	}
	return 0;
}