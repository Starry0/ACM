#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 110;
char str[N];
int a[30];
int main() {
	int n, k;
	cin >> n >> k >> str;
	for(int i = 0; i < n; i ++) {
		a[str[i] - 'a'] ++;
	}
	for(int i = 0; i < 26; i ++) {
		if(a[i] > k) return 0*printf("NO\n");
	}
	printf("YES\n");
	return 0;
}