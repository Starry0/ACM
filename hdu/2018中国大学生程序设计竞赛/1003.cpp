#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N = 1e5+10;

int main() {
	int t, p;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &p);
		for(int i = 0; i < p; i ++) {
			printf("%d",i);
			for(int k = 1; k < p; k ++) {
				printf(" %d",(i+k)%p);
			}printf("\n");
		}
		for(int i = 0; i < p; i ++) {
			printf("0");
			for(int k = 1; k < p; k ++) {
				printf(" %d", (i*k)%p);
			}printf("\n");
		}
	}
	return 0;
}