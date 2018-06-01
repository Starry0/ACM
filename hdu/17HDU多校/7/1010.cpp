#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		int x;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			if(i <= m) printf("%d ",x&1);
			else printf("%d ",x);
		}
	}
	return 0;
}