#include <bits/stdc++.h>
using namespace std;
char str[110];
int main() {
	int n, a, b, c, d;
	a = b = c = d = 0;
	cin >> n >> str;
	for(int i = 0; i < n; i ++) {
		if(str[i] == 'U') a++;
		else if(str[i] == 'D') b++;
		else if(str[i] == 'L') c++;
		else if(str[i] == 'R') d++;
	}
	printf("%d\n",min(a,b)*2+min(c,d)*2);
	return 0;
}
