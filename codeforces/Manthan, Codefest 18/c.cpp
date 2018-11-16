#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s1[N], s2[N];
int main() {
	int n;
	cin >> n >> s1 >> s2;
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		if(s1[i] != s2[i]) {
			if(i+1 < n && s1[i+1] != s2[i+1] && s1[i] != s1[i+1]) {
				s1[i+1] = s2[i+1];
			}
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}