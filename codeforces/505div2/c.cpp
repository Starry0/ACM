#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
int n, sum[N];
char s[N];
int main() {
	cin >> s+1;
	n = strlen(s+1);
	sum[1] = 1; 
	for(int i = 2; i <= n; i ++) {
		if(s[i] != s[i-1]) sum[i] = sum[i-1] + 1;
		else sum[i] = 1;
	}
	int MAX = 1;
	for(int i = 1; i <= n; i ++) MAX = max(MAX, sum[i]);
	if(s[1] != s[n]) {
		int l;
		for(l = 2; l <= n; l ++) {
			if(sum[l] == 1) break;
		}
		MAX = max(MAX, min(n,l-1+sum[n]));
	}
	printf("%d\n",MAX);
	return 0;
}