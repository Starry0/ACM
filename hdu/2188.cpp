#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		if(n%(m+1)) printf("Grass\n");
		else printf("Rabbit\n");
	}
	return 0;
}