#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int t, a;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &a);
		printf("%d\n",(a+1)/2+1);
	}
	return 0;
}