/*#include<cstdio>
#include<iostream> 
using namespace std;
long long a,b,c;
int main(){
	long long l=1,r=int(1e9)<<1;
	cin>>a>>b;
	while(r-l>1){
		c=(l+r)>>1;
		if(c-b<a)l=c;
		else if(c-b>a)r=c;
		else return printf("%lld\n",c);
	}     
	if(l!=r)return printf("%lld\n",r);
	return 0;
}  */


#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int main() {
	ll a, b;
	cin >> a >> b;
	cout << a+b<<endl;
	return 0;
}