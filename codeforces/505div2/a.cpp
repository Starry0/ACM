#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int n, a[30];
char s[N];
int main() {
	cin >> n >> s;
	if(n == 1) return 0*printf("Yes\n");
	for(int i = 0; i < n; i ++) {
		a[s[i]-'a']++;
	}
	int flag = 0;
	for(int i = 0; i < 26; i ++) {
		if(a[i] == 0) continue;
		if(a[i] >= 2) flag = 1;
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}