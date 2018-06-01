#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	while(t--) {
		cin >> x >> y;
		if((x==1 or x== 3) and (y==1 or y ==4)) printf("Win\n6\n");
		else if(x==2 and (y==1 or y == 4)) printf("Equal\n0\n");
		else printf("Win\n4\n");
	}
	return 0;
}