#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N], n;

int main() {
	int q, l1, l2, r1 ,r2;
	cin >> q;
	while(q--) {
		cin >> l1 >> r1 >> l2 >> r2;
		int a = l1, b = r2;
		if(a == b) a++;
		printf("%d %d\n",a,b);
	}
	return 0;
}