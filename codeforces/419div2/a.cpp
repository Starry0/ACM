#include <iostream>
#include <stdio.h>
#define long long ll
using namespace std;

bool check(int x){
	int a, b, c, d;
	a = x/1000;
	b = (x/100)%10;
	c = (x/10)%10;
	d = x%10;
	if(a == d && b == c) return true;
	else return false;
}
int main(){
	int a,b;
	char c;
	cin>>a>>c>>b;
	for(int i = 0; ; i ++){
		if(check(a*100 + b)){
			cout << i << endl;
			return 0;
		}
		b += 1;
		if(b >= 60){
			b = 0;
			a++;
		}
		if(a >= 24){
			a = 0;
		}
	}
	return 0;
}