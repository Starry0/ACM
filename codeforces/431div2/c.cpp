#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	string ans = "";
	cin >> k;
	if(k == 0) return 0*printf("a\n");
	int sum = 0;
	for(int i = 'a'; i <= 'z'; i ++) {
		if(sum == k) break;
		for(int j = 0; j +sum <= k; j ++) {
			sum += j;
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}