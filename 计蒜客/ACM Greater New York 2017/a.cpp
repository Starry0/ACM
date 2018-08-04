#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, k, n;
	cin >> p;
	while(p--)  {
		cin >> k >> n;
		printf("%d %d\n",k,(n+1)*n/2+n);
	}
	return 0;
}