#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
set<ll> st;
void init() {
	st.insert(1);
	st.insert(2);
	int x = 1, y = 2;
	for(int i = 1; i < N; i ++) {
		st.insert(x + y);
		y = y + x;
		x = y - x;
	}
}
int main() {
	init();
	int t;
	ll n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(st.count(n)) printf("B\n");
		else printf("A\n");
	}
	return 0;
}