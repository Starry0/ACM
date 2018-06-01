#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
char str1[11], str2[11], str3[11];

void solve() {
	int len1 = strlen(str1)-1;
	int len2 = strlen(str2)-1;
	int len3 = 0;
	while(len1 >= 0 && len2 >= 0) {
		int ans = str1[len1] - '0' + str2[len2] - '0';
		ans %= 10;
		str3[len3++] = ans+'0';
		len1--;len2--;
	}
	while(len1 >= 0) str3[len3++] = str1[len1--]; 
	while(len2 >= 0) str3[len3++] = str2[len2--]; 
	for(int i = 0; i < len3/2; i ++) {
		swap(str3[i],str3[len3-1-i]);
	}
	int i = 0;
	while(str3[i] == '0')i++;
	if(i == len3) printf("0");
	for(; i < len3; i ++) {
		printf("%c",str3[i]);
	}
	printf("\n");
}
int main() {
	while(cin >> str1 >> str2) {
		solve();
		memset(str1,0, sizeof(str1));
		memset(str2,0, sizeof(str2));
		memset(str3,0, sizeof(str3));
	}
	return 0;
}