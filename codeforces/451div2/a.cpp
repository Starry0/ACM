#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x = n%10;
	if(x <= 5) printf("%d\n",n-x);
	else printf("%d\n",n+(10-x));
	return 0;
}