#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 220;
char s[N][N];

int main() {
	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		memset(s, 0, sizeof(s));
		if(n%2==1&&m%2==1) {
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= m; j ++) printf("(");
				printf("\n");
			}
		} else if(n%2==1&&m%2==0||(n%2==0&&m%2==0&&n>=m)) {
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= m; j ++) {
					if(j <= m/2) printf("(");
					else printf(")");
				}printf("\n");
			}
		} else if(n%2==0&&m%2==1 || (n%2==0&&m%2==0&&n<m)) {
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= m; j ++) {
					if(i <= n/2) printf("(");
					else printf(")");
				}printf("\n");
			}
		} 
	}
	return 0;
}