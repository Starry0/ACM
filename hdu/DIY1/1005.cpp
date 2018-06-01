#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 110;
char str[N];
bool flag;
bool check() {
	int len = strlen(str), ans = 0;
	for(int i = 0; i < len; i ++) {
		if(str[i] == '0') ans++;
		else if(str[i] == '1') {
			if(ans == 1) return 0;
			ans --;
		}
	}
	return ans == 1;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", str);
		if(check())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
