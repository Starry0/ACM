#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int MAX = 0;
	MAX = max(a+b*c,max(a*(b+c),max(a*b*c,max((a+b)*c,a+b+c))));
	cout << MAX<< endl;
	return 0;
}