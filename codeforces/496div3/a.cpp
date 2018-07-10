#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int a[N];

int main() {
	int n;
	cin >> n;
	std::vector<int> v;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int tmp = 1;
	for(int i = 2; i <= n; i ++) {
		if(a[i] == 1) v.push_back(a[i-1]);
	}
	v.push_back(a[n]);
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i ++) {
		cout << v[i] << ' ';
	}

	return 0;
}