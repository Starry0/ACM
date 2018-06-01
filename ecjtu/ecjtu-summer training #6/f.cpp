#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n == 1){
			cout << "Bob\n";
		}else cout << "Alice\n";
	}
	return 0;
}