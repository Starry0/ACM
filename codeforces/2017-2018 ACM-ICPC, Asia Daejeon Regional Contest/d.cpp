#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
map<int,int> mp;
int f(int x) {
	int ans = 0;
	while(x) {
		int y = x%10;
		ans += y*y;
		x /= 10;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	while(true) {
		n = f(n);
		if(n == 1) return 0*printf("HAPPY\n");
		if(mp.count(n)) break;
		mp[n] = 1;
	}
	printf("UNHAPPY\n");
	return 0;
}