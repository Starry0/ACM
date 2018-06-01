#include <bits/stdc++.h>
using namespace std;
char str[5001];
int main() {
	cin >> str;
	int len = strlen(str);
	int ans = 0;
	for(int i = 0; i < len; i ++) {
		int l = 0, r = 0;
		for(int j = i; j < len; j ++) {
			if(str[j] == '(') l++,r++;
			if(str[j] == ')') l--,r--;
			if(str[j] == '?') l++,r--;
			if(l < 0) break;
			if(r < 0) r+= 2;
			if(r == 0) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
