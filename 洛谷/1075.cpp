#include <bits/stdc++.h>
using namespace std;

bool isPreme(int x) {
	for(int i = 2; i <= sqrt(x); i ++) {
		if(x%i == 0) return false;
	}
	return true;
}

int main() {
	int n, MAX = 1;
	cin >> n;
	for(int i = 2; i <= sqrt(n); i ++) {
		if(n%i == 0) {
			if(isPreme(i)) MAX = max(MAX, i);
			if(isPreme(n/i)) MAX = max(MAX, n/i);
		}
	}
	cout << MAX << endl;
	return 0;
}