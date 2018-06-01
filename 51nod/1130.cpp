#include <iostream>
#include <stdio.h>
#include <math.h>
#define ll long long
using namespace std;

int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ll x = (ll)(log10(sqrt(2.0*acos(-1.0)*n))+n*(log10(n)-log10(exp(1.0)))+1);
		if(n==1)x++;
		cout << x << endl;
	}
	return 0;
}

