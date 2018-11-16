#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int a[3], b[3];
	cin >> n;
	for(int i = 0; i < 3; cin >> a[i] >> b[i], i++);
	int MAX = (n+a[0]-1)/a[0]*b[0];
	MAX = min(MAX, (n+a[1]-1)/a[1]*b[1]);
	MAX = min(MAX, (n+a[2]-1)/a[2]*b[2]);
	cout << MAX << endl;
	return 0;
}