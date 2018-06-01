#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;

int main() {
	int q, t, L , T;
	cin >> q;
	while(q--) {
		cin >> L >> t >> T;
		int a = T, b = T - t;
		a %= (2*L);
		b %= (2*L);
		// printf("%d %d\n",a,b);
		 if(a > L) a = 2*L - a;
		 if(b <= L) b = L - b;
		 else if(b > L) b = b - L;
		 printf("%d\n",abs(a-b));
	}
	return 0;
}