#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int main() {
	int x, a, b;
	cin >> x >> a >> b;
	if(abs(x-a) < abs(x-b)) printf("A\n");
	else printf("B\n");
	return 0;
}