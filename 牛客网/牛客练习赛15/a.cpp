#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#define ll long long
using namespace std;
const int N = 110;
char str[N];
int main() {
	cin >> str;
	ll ans, tmp = 0, f = 1;
	for(int i = 0; str[i]; i ++) {
		if(str[i] >= '0' && str[i] <= '9') {
			if(i > 0 && str[i-1] =='-') f = -1;
			else f = 1;
			while(str[i] >= '0' && str[i] <= '9') {
				tmp = tmp*10 + str[i] - '0';
				i++;
			}
			i--;
			ans = f*tmp;
			tmp = 0;
		}
	}
	cout << ans << endl;
	return 0;
}