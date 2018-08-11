#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char s1[N],s2[N];
int s[N][N], a[N], b[N];
int main() {
	int r, c, x, y;
	cin >> s1 >> s2;
	r = strlen(s1);
	c = strlen(s2);
	for(int i = 1; i <= r; i ++) {
		for(int j = 1; j <= c; j ++) s[i][j] = 1;
	}
	x = c%2;
	y = r%2;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= r; i ++) if((s1[i-1]-'0') != x) a[cnt1++] = i;
	for(int i = 1; i <= c; i ++) if((s2[i-1]-'0') != y) b[cnt2++] = i;
	if((cnt2+cnt1)&1) return 0*printf("-1\n");
	while(cnt1 < cnt2) a[cnt1++] = 1;
	while(cnt2 < cnt1) b[cnt2++] = 1;
	sort(a,a+cnt1);
	sort(b,b+cnt2);
	for(int i = 0; i < cnt1; i ++) s[a[i]][b[i]] = 0;
	for(int i = 1; i <= r; i ++) {
		for(int j = 1; j <= c; j ++) printf("%d%c",s[i][j]," \n"[j==c]);
	}
	return 0;
}