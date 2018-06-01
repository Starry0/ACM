#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	int k = a/b;
	printf("%.2lf\n", a - k*b);
	return 0;
}