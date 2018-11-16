#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
char s[N];
int a[N], b[N];
int main() {
	cin >> s;
	int len = strlen(s);
	for(int i = 0; i < len; i ++) {
		if(s[i] == '0') {
			a[i+1] = a[i] + 1;
			b[i+1] = b[i];
		} else{
			a[i+1] = a[i];
			b[i+1] = b[i] + 1;
		}
	}
	b[len+1] = b[len]; a[len+1] = a[len];
	for(int i = 1; i <= len+1; i ++) {
		if(a[i-1] == b[len]-b[i-1]) return 0*printf("%d\n",i-1);
	}
	printf("-1\n");
	return 0;
}