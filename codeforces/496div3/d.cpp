#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
char str[N];
int main() {
	scanf("%s", str);
	int len = strlen(str);
	int ans = 0, tmp = 0, sum = 0, n = 0;
	for(int i = 0; i < len; i ++) {
		tmp = (str[i]-'0') % 3;
		sum += tmp;
		n++;
		if(tmp == 0 || sum%3==0 || n == 3) {
			ans++;
			sum = n = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
