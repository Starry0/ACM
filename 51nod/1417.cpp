/*
设正面为x/(x+y) 反面为y/(x+y) 
求x(a+c) = y(c+b)
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll a ,b, c, x, y;
		cin >> a >> b;
		c = (a+b)/2;
		x = c+b, y = a+c;
		y += x;
		ll tmp = __gcd(x,y);
		x /= tmp;
		y /= tmp;
		printf("%lld/%lld\n",x,y);
	}
	return 0;
}