#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
	int t, x;
	while(cin >> t, t) {
		int ans = 0;
		for(int i = 1; i <= t; i ++) {
			cin >> a[i];
			ans ^= a[i];
		}
		if(!ans)printf("0\n");
		else {
			int cnt = 0;
			for(int i = 1; i <= t; i ++) {
				if((ans^a[i]) < a[i]) cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}