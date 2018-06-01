#include <bits/stdc++.h>
using namespace std;
char str[1010];
int main() {
	cin >> str;
	int len = strlen(str);
	cout << str;
	for(int i = len-1; i >= 0; i --) cout << str[i];
	cout << endl;
	return 0;
}
