#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	b = abs(a-b);
	a = 0;
	if(c==d){
		if(b%c==0 && b <= (n-1)*c)
			cout << "YES\n";
		else cout << "NO\n";
	}else{
		if(c>d){
			swap(c,d);
		}
		if(b > d*(n-1))
			cout << "No\n";
		else {
			cout << "YES\n";
		}
	}
	return 0;
}