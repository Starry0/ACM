#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
string a[N];
bool cmp(string s1, string s2) {
	return s1+s2 < s2 + s1;
}
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if(cnt + a[i].length() <= 1000) {
			cout << a[i];
			cnt += a[i].length();
			if(cnt == 1000) printf("\n"), cnt = 0;
		} else {
			int j;
			for(j = 0; j < a[i].length(); j ++) {
				printf("%c",a[i][j]);
				cnt++;
				if(cnt == 1000) {
					printf("\n");
					cnt = 0;
					break;
				}
			}
			j++;
			while(j < a[i].length()) printf("%c",a[i][j++]),cnt++;
		}
	}
	return 0;
}