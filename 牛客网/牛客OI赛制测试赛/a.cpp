#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e6+10;
char s[N];
int main() {
	cin >> s;
	int len = strlen(s);
	if((s[len-1]-'0')%2==0)printf("1\n");
	else printf("-1\n");
	return 0;
}