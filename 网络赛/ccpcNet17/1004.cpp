#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int N = 1e6+10;
char str[N], str1[N];
int len, len1, nex[N];
void init() {
	int j = nex[0] = -1;
	int i = 0;
	while(i < len1) {
		if(j == -1 || str1[i] == str1[j]) nex[++i] = ++j;
		else j = nex[j];
	}
}
ll kmp() {
	ll ans = 0, i = 0, j = 0;
	while(i < len) {
		if(j == -1 || str[i] == str1[j]) {
			++i, ++j;
			if(j == len1) {
				ans += j*(j+1)/2;
				ans %= mod;
				j = nex[j];
			}
		} else {
			ans += j*(j+1)/2;
			ans %= mod;
			j = nex[j];
		}
	}
	while(j != -1) {
		ans += j*(j+1)/2;
		ans %= mod;
		j = nex[j];
	}
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s %s",str,str1);
		len = strlen(str), len1 = strlen(str1);
		reverse(str, str+len);
		reverse(str1, str1+len1);
		init();
		printf("%lld\n",kmp());
	}
	return 0;
}