#include <iostream>
#include <stdio.h>
using namespace std;
const int m = 9973;
int extgcd(int a, int b, int &x, int &y){
    int d = a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }else{
        x = 1; y = 0;
    }
    return d;
}
int main() {
	int t, b, n, x, y;
	cin >>t;
	while(t--) {
		cin >> n >> b;
		extgcd(b,m,x,y);
		x = (x%m+m)%m;
		printf("%d\n",(x*n)%m);
	}
	return 0;
}