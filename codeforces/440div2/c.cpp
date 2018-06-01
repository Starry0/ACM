#include <bits/stdc++.h>
using namespace std;

int main() {
	int q, n;
	cin >> q;
	while(q--) {
		cin >> n;
		if(n&1) {
			if(n < 9) printf("-1\n");
			else {
				if((n-1)%4==0) printf("%d\n",1+(n-9)/4);
				else if(n == 11) printf("-1\n");
				else printf("%d\n",2+(n-15)/4);
			}
		} else {
			if(n == 2) printf("-1\n");
			else if(n%4 == 0) printf("%d\n",n/4);
			else printf("%d\n",(n-2)/4);
		}
	}
	return 0;
}