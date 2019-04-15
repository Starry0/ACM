#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
char s[N];
int n, k, a[N];
int main() {
	cin >> n >> k >> s;
	int l = 0;
	for(int i = 0; i < 26; i ++) {
		int ans = 0;
		for(int j = 0; j < n; j ++) {
			if(s[j] == ('a'+i)) a[j+1] = a[j]+1;
			else a[j+1] = 0;
			// if(i == 0) printf("%d",a[j+1]);
			if(a[j+1] == k) {
				ans ++;
				a[j+1] = 0;
			}
		}
		l = max(l, ans);
	}
	printf("%d\n",l);
	return 0;
}