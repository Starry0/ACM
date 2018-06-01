#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int x;
	cin >> x;
	int a = x/100, b = x/10%10, c = x%10;
	if((a*a*a+b*b*b+c*c*c) == x) printf("YES\n");
	else printf("NO\n");
	return 0;
}