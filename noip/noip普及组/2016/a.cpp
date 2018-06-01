#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, a1, a2, b1, b2, c1, c2, ans1, ans2, ans3;
	cin >> x >>a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	ans1 = (x/a1+(x%a1?1:0))*a2;
	ans2 = (x/b1+(x%b1?1:0))*b2;
	ans3 = (x/c1+(x%c1?1:0))*c2;
	cout << min(ans1, min(ans2, ans3)) << endl;
	return 0;
}