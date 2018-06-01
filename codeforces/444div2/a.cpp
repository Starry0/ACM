#include <bits/stdc++.h>
using namespace std;
char str[110];
int main() {
	int flag = 0, ans = 0;
	cin >> str;
	for(int i = 0; str[i]; i ++) {
		if(str[i] == '1') flag = 1;
		if(str[i] == '0' && flag) ans++;
	}
	if(ans >= 6) printf("yes\n");
	else printf("no\n");
	return 0;
}