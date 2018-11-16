#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1001;
int a[N];
int main() {
	for(int i = 1; i < N; i ++) {
		a[i] = 1;
		for(int j = 1; j <= i/2; j ++)  a[i] += a[j];
	}
	int n;
	cin >> n;
	cout << a[n] << endl;
	return 0;
}