#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	double r, x, p;
	cin >> r >> x >> p;
	printf("%.2lf", x*pow((100+r)/100,p));
	return 0;
}