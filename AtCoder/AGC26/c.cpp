#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char str[N];
int n;
int a[N];
int main() {
	cin >> n;
	cin >> str;
	for(int i = 0; str[i]; i ++) {
		a[str[i]-'a'] ++;
	}
	for(int i = 0; i < 26; i ++) {
		if(a[i]%2==1) return 0*printf("0\n");
	}
	
	return 0;
}