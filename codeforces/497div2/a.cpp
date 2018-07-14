#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
char str[110];
map<char,int> mp;
int main() {
	mp['e'] = mp['a'] = mp['o'] = mp['u'] = mp['i'] = 1;
	cin >> str;
	for(int i = 0; str[i]; i ++) {
		if(str[i] == 'n') continue;
		if(mp[str[i]] == 0 ) {
			if(mp[str[i+1]] != 1) {
				// printf("%c %c\n",str[i],str[i+1] );
				return 0*printf("no\n");
			}
		}
	}printf("yes\n");
	return 0;
}