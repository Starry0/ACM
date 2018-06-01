#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	int a,b;
	cin >> a>>b;
	if((a+b)%3==0 || a%3==0 || b%3==0){
		cout << "Possible" << endl;
	}
	else cout << "Impossible" << endl; 
	return 0;
}