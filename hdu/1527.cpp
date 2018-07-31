#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF) {
		if(a > b) swap(a, b);
		if(a == int((b-a)*(sqrt(5)+1)/2)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}