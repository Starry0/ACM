#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, cnt = 0;
	cin >> a >> b >> c;
	a %= b;
	for(int i = 0; i < 1000; i ++) {
		if(a*10 < b && c == 0) return 0*printf("%d\n",cnt+1);
		while(a < b) {
			a*= 10,cnt++;
		}
		
		int tmp = a/b;
		if(tmp == c) return 0*printf("%d\n",cnt);
		a -= tmp*b;
		if(a == 0) {
			if(c == 0) return 0*printf("%d\n",cnt+1);
			break;
		}
	}
	printf("-1\n");
	return 0;
}