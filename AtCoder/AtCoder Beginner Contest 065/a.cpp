#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll x,a,b;
	cin >> x >> a >> b;
	if(x < b-a){
		cout << "dangerous" << endl;
	}else if(b <= a){
		cout << "delicious" << endl;
	}else if(b-a <= x && b-a>0){
		cout << "safe" << endl;
	}
	return 0;
}