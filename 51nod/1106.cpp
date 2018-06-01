#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
bool isPrime(int num){
	for(int i = 2; i <= sqrt(num); i ++){
		if(num%i==0)return false;
	}
	return true;
}
int main(){
	int n,num;
	for(cin>>n;n--;){
		cin>>num;
		if(isPrime(num))cout <<"Yes\n";
		else cout << "No\n";
	}
	return 0;
}