#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
char s[N];
int n, ans;

int main() {
	cin >> n >> s;
	for(int i = 0; i < n-1; i ++) {
		if(s[i] == s[i+1]) {
			ans ++;
			if(s[i]!='R'&&s[i+2]!='R') s[i+1] = 'R';
			else if(s[i]!='G'&&s[i+2]!='G') s[i+1] = 'G';
			else if(s[i]!='B'&&s[i+2]!='B') s[i+1] = 'B';
		}
	}
	printf("%d\n",ans);
	for(int i = 0; i < n; i ++) printf("%c",s[i]);
	return 0;
}