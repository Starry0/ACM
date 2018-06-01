#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		bool flag = false;
		for(int i = 0; i < 33; i ++) {
			for(int j = 0; j < 15; j ++) {
				if(3*i + 7*j == x) flag = true;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}