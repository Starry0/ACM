#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int ans = 0, x;
		for(int i = 0; i < 4; i ++) {
			cin >> x;
			if(x > 0) ans ++;
		}
		if(ans == 0) printf("Typically Otaku\n");
		else if(ans == 1) printf("Eye-opener\n");
		else if(ans == 2) printf("Young Traveller\n");
		else if(ans == 3) printf("Excellent Traveller\n");
		else if(ans == 4) printf("Contemporary Xu Xiake\n");
		
	}
	return 0;
}