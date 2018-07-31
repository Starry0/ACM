#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;

int main() {
	int t, a, b, c, x, y;
	char s[20];
	cin >> t;
	while(t--) {
		x = y = 0;
		scanf("%d%d%s", &a, &b, s);
		a = (a-8+24)%24;
		int i, len = strlen(s);
		for(i = 4; s[i] && s[i] != '.'; i++) {
			x = x*10 + s[i]-'0';
		}
		if(i < len) y = s[i+1]-'0';
		y *= 6;
		if(s[3] == '+') {
			b += y;
			if(b >= 60) {
				b%=60;
				a++;
			}
			a += x;
			if(a >= 24) a%=24;
			// printf("%d %d %d %d\n",a,b,x,y );
		} else {
			b -= y;
			if(b < 0) {
				b += 60;
				a--;
			}
			a -= x;
			if(a < 0) a += 24;
		}
		printf("%02d:%02d\n",a,b);
	}
	return 0;
}