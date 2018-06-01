#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, sum = 0, l, r = 0;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> l;
		sum += l;
	}
	cin >> n;
	for(int i = 0; i < n && sum > r; i ++){
		cin>> l >> r;
	}
	//cout << sum<<endl;
	cout << (sum > r ? -1 : max(sum, l)) << endl;
	return 0;
}