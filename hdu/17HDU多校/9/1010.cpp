#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 2510;
char str[N], str1[N];
bool dp[N][N];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(dp, false, sizeof(dp));
		scanf("%s %s",str+1, str1+1);
		int len = strlen(str+1), len1 = strlen(str1+1);
		dp[0][0] = true;
		for(int i = 1; i <= len1; i ++) {
			if(i == 2 && str1[i] == '*') dp[i][0] = true;
			for(int j = 1; j <= len; j ++) {
				if(str1[i] == '.' || str1[i] == str[j])
					dp[i][j] = dp[i-1][j-1];
				else if(str1[i] == '*') {
					dp[i][j] = dp[i-2][j] | dp[i-1][j];
					if((dp[i-1][j-1] || dp[i][j-1]) && str[j-1] == str[j])
						dp[i][j] = true;
				}
			}
		}
		printf("%s\n",dp[len1][len]?"yes":"no");
	}
	return 0;
}