#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	if(n == 0) {
		cin >> x;
		cout << x << endl;
		return 0;
	}
	bool flag = 0;
	for(int i = n; i >= 0; i --) {
		cin >> x;
		if(x == 0) continue;
		if(!flag) {
			if(i != 0) {
				if(abs(x) != 1) cout << x << "x";
				else if(x == 1) cout << "x";
				else if(x == -1) cout << "-x";
				if(i != 1) cout << "^"<<i;
			} else cout << x;
			flag = 1;
		} else {
			if(i == 0) {
				if(x < 0) {
					cout << x << endl;
				}else {
					cout << "+"<<x<<endl;
				}
				continue;
			}
			if(x < 0) {
				if(x == -1) cout << "-x";
				else cout << x << "x";
			}else {
				if(x == 1) cout << "+x";
				else cout << "+"<<x<<"x";
			}
			if(i != 1) cout << "^"<<i;
		} 
	}
	return 0;
}