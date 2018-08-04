#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 550;
char s[N];
bool isoper(char ch) {
	if(ch == '*' || ch == '+') return true;
	return false;
}
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> s;
		int len = strlen(s);
		bool flag = true;
		for(int i = 0; i < len; i ++) {
			if((i == 0) && s[i] == '?') {
				s[i] = '1';
			} else if(i == len-1 && s[i] == '?') {
				if(s[i-1] == '0' && isoper(s[i-2])) {
					flag = false;
					break;
				} else {
					s[i] = '1';
				}
			} else if((i == 0|| i==len-1) && isoper(s[i])) {
				flag = false;
				break;
			} else if(s[i] == '?') {
				if(isdigit(s[i-1])) {
					if(s[i-1] == '0' && isoper(s[i-2])) {
						s[i] = '+';
					} else {
						s[i] = '1';
					}
				} else if(isoper(s[i-1])) {
					s[i] = '1';
				} else {
					flag = false;
					break;
				}
			} else if(isoper(s[i]) && isoper(s[i-1])) {
				flag = false;
				break;
			} else if(isoper(s[i])) {
				if(s[i+1] == '0' && isdigit(s[i+2])){
					flag = false;
					break;
				}
			} else if(isdigit(s[i])) {
				if((i==0 || isoper(s[i-1])) && s[i] == '0' && isdigit(s[i+1])) {
					flag = false;
					break;
				}
			}
		}	
		if(flag) printf("%s\n",s);
		else printf("IMPOSSIBLE\n");
		memset(s, 0, sizeof(s));
	}
	return 0;
}