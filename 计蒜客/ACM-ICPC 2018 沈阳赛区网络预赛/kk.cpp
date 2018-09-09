#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int a[] = {1,2,3,5,7,11,13, 17, 23, 31, 37, 53, 71, 73, 113, 131, 137, 173, 311, 317, 10000};
char s[110];
int main() {
	int t;
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ca ++){
		scanf("%s",s);
		int len = strlen(s);
		if(len > 3) printf("Case #%d: 317\n",ca);
		else {
			int ans = 0;
			for(int i = 0; s[i]; i ++) ans = ans*10 + s[i] - '0';
			for(int i = 0; i < 21; i ++) {
				if(a[i] > ans) {
					printf("Case #%d: %d\n",ca,a[i-1]);
					break;
				}
			}
		}
	}
	return 0;
}