#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = 1e6+10;
const int M = 1e4+10;
char s1[M], s2[N];
int nex[M], n;
void init() {
	int j = nex[0] = -1, i = 0;
	int len = strlen(s1);
	while(i < len) {
		if(j == -1 || s1[i] == s1[j]) {
			nex[++i] = ++j;
		} else j = nex[j];
	}
}
int KMP() {
	int len1 = strlen(s1), len2 = strlen(s2);
	int i = 0, j = 0, sum = 0;
	while(j < len2) {
		if(i == -1 || s1[i] == s2[j]) {
			i++;j++;
		} else i = nex[i];
		if(i == len1) sum ++;
	}
	return sum;
}
int main() {
	// cin >> n;
	scanf("%d",&n);
	while(n--) {
		scanf("%s%s",s1,s2);
		// cin >> s1 >> s2;
		init();
		printf("%d\n",KMP());
	}
	return 0;
}