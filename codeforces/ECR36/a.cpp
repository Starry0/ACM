#include <iostream>
using namespace std;

int main() {
	int n, k, x, ans = 0x3f3f3f3f;
	cin >> n >> k;
	for(int i = 0; i < n; i ++){
		cin >> x;
		if(k%x == 0) ans = min(ans,k/x);
	}
	cout << ans << endl;
	return 0;
}