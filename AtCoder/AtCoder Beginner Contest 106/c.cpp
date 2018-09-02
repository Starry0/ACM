#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 110;
char s[N];
int main(){
	ll k, l = 0;
	cin >> s >> k;
	ll len = strlen(s);
	while(l < len && s[l] == '1') l ++;
	if(l+1 <= k) printf("%c\n",s[l]);
	else printf("1\n");
	return 0;
}