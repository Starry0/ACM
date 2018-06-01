#include <bits/stdc++.h>
using namespace std;
char str[10];
int main() {
	int n, tmp, x = 0, y = 1023;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> str >> tmp;
		if(str[0] == '|') {
			x |= tmp;
			y |= tmp;
		} else if(str[0] == '^') {
			x ^= tmp;
			y ^= tmp;
		} else {
			x &= tmp;
			y &= tmp;
		}
	}
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 10; i ++) {
		if((x&(1<<i)) > 0 && (y&(1<<i)) > 0) {
			b += (1<<i);
			c += (1<<i);
		} else if((x&(1<<i)) > 0 && (y&(1<<i)) == 0) {
			a += (1<<i);
			c += (1<<i);
		} else if((x&(1<<i)) == 0 && (y&(1<<i)) > 0) {
			c += (1<<i);
		} else {
			
		}
	}
	printf("3\n");
	printf("^ %d\n", a);
	printf("| %d\n", b);
	printf("& %d\n", c);
	return 0;
}