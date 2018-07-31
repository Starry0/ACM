#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n <= m) {
			for(int i = n; i <= m; i ++) printf("%d%c",i," \n"[i==m]);
		} else if(n%(m+1) == 0) printf("none\n");
		else printf("%d\n",n%(m+1));
	}
	return 0;
}