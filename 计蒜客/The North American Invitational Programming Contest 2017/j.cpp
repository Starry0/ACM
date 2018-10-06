#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char str[N];
int main() {
	cin >> str;
	int len = strlen(str);
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < len; i ++) {
		if(str[i] == 'W')ans1++;
		else ans2++;
 	}		
 	if(ans1 == ans2) printf("1\n");
 	else printf("0\n");
	return 0;
}
