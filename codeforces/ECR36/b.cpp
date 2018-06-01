#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	if(c==1 &&d==a) cout<<0;
	else if(c==1) cout<<abs(d-b)+1;
	else if(d==a) cout<<abs(c-b)+1;
	else cout<<min(abs(c-b)+(d-c),abs(d-b)+(d-c))+2;
	return 0;
}