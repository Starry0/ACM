#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
char s1[N], s2[N];

int main() {
	ll x = 0, y = 0, x1 = 0, y1 = 0, n;
	cin >> n;
	scanf("%s%s",s1,s2);
	for(int i = 0; i < n; i ++) {
		if(s2[i] == '0' && s1[i] == '0') x++;
		else if(s2[i] == '0' && s1[i] == '1') y++;
		if(s1[i] == '0') x1++;
		else y1++;
	}
	printf("%lld\n",x*y1+y*x1-x*y);
	return 0;
}