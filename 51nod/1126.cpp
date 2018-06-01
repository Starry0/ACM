#include <bits/stdc++.h>
using namespace std;
int fa[1111];
int main() {
	int n, a, b;
	cin >> a >> b >> n;
	fa[1] = 1; fa[2] = 1;
	int cnt = 3, index = 1;
	for( ; ; cnt ++) {
		fa[cnt] = (a*fa[cnt - 1] + b * fa[cnt - 2])% 7; 
		while(fa[cnt] < 0) fa[cnt] += 7;
		index = 1;
		while(index < cnt - 2) {
			if(fa[index] == fa[cnt-1] && fa[index+1] == fa[cnt]) goto tt;
			else index++;
		}
		if(fa[cnt-1] == fa[1] && fa[cnt] == fa[2]) break;
	}
	tt:;
	cnt = cnt - index - 1;
	if(n <= index) printf("%d\n",fa[n]);
	else {
		n = (n - index + 1) %cnt;
		if(n == 0) printf("%d\n",fa[index+cnt-1]);
		else printf("%d\n",fa[index+n-1]);
	}
	return 0;
}