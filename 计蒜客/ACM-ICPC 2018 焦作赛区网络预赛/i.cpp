#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t, a[4];
	while(cin >> a[0] >> a[1] >> a[2]) {
		if((a[0]%2==0 || a[1]%2==0 || a[2]%2==0)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}