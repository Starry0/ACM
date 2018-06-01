#include <iostream>
#include <stdio.h>
using namespace std;

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
	int a, b, x, y;
	while(cin >> a >> b) {
		int d = extgcd(a, b, x, y);
		if(d != 1) {
			printf("sorry\n");
		} else{
			int tx = x;
			x = (x%b+b)%b;
			y = y - (x-tx)/b*a;
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}