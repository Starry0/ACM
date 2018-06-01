#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, ans = 0, cnt = 0; 
	cin >> k;
	for(int i = 1; ; i++) {
		for(int j = 1; j <= i; j ++) {
			ans += i;
			cnt ++;
			if(cnt == k) {
				return 0*printf("%d\n",ans);
			}
		}
	}
	return 0;
}