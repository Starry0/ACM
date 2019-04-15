#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
char s[N], s1[N], s2[N];
int n, a[4];

int main() {
	cin >> n >> s;
	map<int,char> mp;
	mp[0] = 'R'; mp[1] = 'G'; mp[2] = 'B';
	int ans = N*2;
	a[1] = 1, a[2] = 2;
	do{
		s1[0] = mp[a[0]], s1[1] = mp[a[1]], s1[2] = mp[a[2]];
		for(int q = 3; q < n; q ++) {
			s1[q] = s1[q-3];
		}
		int cnt = 0;
		for(int q = 0; q < n; q ++) {
			if(s1[q] != s[q]) cnt++;
		}
		if(cnt < ans) {
			ans = cnt;
			strcpy(s2,s1);
		}
	}while(next_permutation(a,a+3));
	printf("%d\n",ans);
	for(int i = 0; i < n; i ++) printf("%c",s2[i]);
	return 0;
}