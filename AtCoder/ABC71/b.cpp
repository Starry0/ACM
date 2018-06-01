#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
char str[N];
int a[30];
int main() {
	cin >> str;
	for(int i = 0; str[i]; i ++) a[str[i]-'a']++;
	for(int i = 0; i < 26; i ++) {
		if(a[i] == 0) return 0*printf("%c\n",i+'a');
	}
	printf("None\n");
	return 0;
}