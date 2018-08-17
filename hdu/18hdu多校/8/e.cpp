#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5;
char s[N][N], s1[N];


void C(int x, int y) {
	char tmp = s[x][y];
	s[x][y] = s[x+1][y];
	s[x+1][y] = s[x+1][y+1];
	s[x+1][y+1] = s[x][y+1];
	s[x][y+1] = tmp;
}
void R(int x, int y) {
	char tmp = s[x][y];
	s[x][y] = s[x][y+1];
	s[x][y+1] = s[x+1][y+1];
	s[x+1][y+1] = s[x+1][y];
	s[x+1][y] = tmp;
}
int main() {
	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= 3; i ++) cin >> s[i]+1;
		while(n--) {
			cin >> s1;
			if(s1[1] == 'C') {
				if(s1[0] == '1') C(1,1);
				else if(s1[0] == '2') C(1,2);
				else if(s1[0] == '3') C(2,1);
				else if(s1[0] == '4') C(2,2);
			} else if(s1[1] == 'R') {
				if(s1[0] == '1') R(1,1);
				else if(s1[0] == '2') R(1,2);
				else if(s1[0] == '3') R(2,1);
				else if(s1[0] == '4') R(2,2);
			}
		}
		for(int i = 1; i <= 3; i ++) printf("%s\n",s[i]+1);
	}
	return 0;
}