#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
string s[10];
int n;
bool cmp(string s1, string s2) {
	return s1.length() < s2.length();
}
int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i ++) cin >> s[i];
		sort(s,s+n, cmp);
		int len = s[0].length();
		string ans = "";
		for(int i = 1; i < (1<<len); i ++) {
			string tmp = "";
			for(int j = 0; j < len; j ++) {
				if((i>>j)&1) tmp += s[0][j];
			}
			string tmp1="", tmp2 = "";
			for(int j = 1; j < tmp.length(); j ++) {
				tmp1 = tmp.substr(j,len) + tmp.substr(0,j);
				if(tmp2 == "") tmp2 = tmp1;
				else if(tmp2 > tmp1) tmp2 = tmp1;
			}
			if(tmp2 != "" && tmp2 < tmp) tmp = tmp2;
			// cout <<i<<' ' <<tmp << endl;
			int flag = 0;
			for(int j = 1; j < n; j ++) {
				int lenj = s[j].length();
				for(int k = 0; k < lenj; k ++) {
					int cnt = 0;
					if(tmp[0] == s[j][k]) {
						for(int l = 0; l < lenj; l ++) {
							if(tmp[cnt] == s[j][(k+l)%lenj]) cnt++;
							if(cnt == tmp.length()) {
								flag++;break;
							}
						}
					}
					if(cnt == tmp.length()) break;
				}
			}
			if(flag == n-1) {
				if(ans == "") ans = tmp;
				else if(tmp.length() > ans.length()) ans = tmp;
				else if(tmp.length() == ans.length() && tmp < ans) ans = tmp;
			}
		}
		if(ans == "") printf("0\n");
		else cout << ans << endl;
	}
	return 0;
}