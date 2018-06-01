#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,g,b;
	cin >> r >>  g >> b;
	if((r*100+g*10+b)%4){
		cout << "NO" << endl;
	}else cout << "YES" << endl;
	return 0;
}