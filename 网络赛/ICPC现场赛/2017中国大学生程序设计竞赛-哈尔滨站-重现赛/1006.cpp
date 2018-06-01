#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int a = 1, b = n/2+1 +((n&1)?1:0);
		for(int i = 1; i <= n; i ++) {
			if(i&1){
				printf("%d%c",a++,i==n?'\n':' ');
			} else {
				printf("%d%c",b++,i==n?'\n':' ');
			}
		}
	}
	return 0;
}