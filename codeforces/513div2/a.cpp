#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n;
char s[110];
int main() {
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; s[i]; i ++) {
		if(s[i] == '8') ans ++;
	}
	printf("%d\n",min(n/11,ans));
	return 0;
}
