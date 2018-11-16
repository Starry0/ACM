/*
取其中一种糖果，就一定知道另一种糖果取多少种，设第一种糖果取a,第二种糖果取b。
最优情况下，min(a,b) <= Sqrt(c)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll c, wr, wb, hr, hb;
	cin >> c >> hr >> hb >> wr >> wb;
	ll MAX = 0;
	for(int i = 0; i <= sqrt(c); i ++) {
		if(i*wr <= c) MAX = max(MAX, 1LL*i*hr+(c-i*wr)/wb*hb);
		if(i*wb <= c) MAX = max(MAX, 1LL*i*hb+(c-i*wb)/wr*hr);
	}
	cout << MAX << endl;
	return 0;
}