#include <bits/stdc++.h>
using namespace std;
char s[15];
int main() {
	cin >> s;
	int ans = 0;
	ans = (s[0]-'0')+2*(s[2]-'0')+3*(s[3]-'0')+4*(s[4]-'0')+5*(s[6]-'0')+
	6*(s[7]-'0')+7*(s[8]-'0')+8*(s[9]-'0')+9*(s[10]-'0');
	ans %= 11;
	// cout << s[12] << ' ' << ans << endl;
	if(ans == s[12]-'0') cout << "Right" << endl;
	else if(ans == 10 && s[12] == 'X') cout << "Right" << endl;
	else {
		if(ans == 10) s[12] = 'X';
		else s[12] = ans+'0';
		cout << s << endl;
	}
	return 0;
}