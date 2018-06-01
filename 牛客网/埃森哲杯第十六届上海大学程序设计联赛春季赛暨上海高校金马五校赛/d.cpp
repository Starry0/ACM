#include <iostream>
using namespace std;

int main() {
	int t, l1, l2, r1, r2, mod;
	cin >> t;
	while(t--) {
		cin >> l1 >> r1 >> l2 >> r2 >> mod;
		if(r2-l2 >= mod-1) cout << "LOSE\n";
		else cout << "WIN\n";
	}
	return 0;
}