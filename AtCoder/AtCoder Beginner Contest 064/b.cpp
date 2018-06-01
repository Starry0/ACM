#include <bits/stdc++.h>
using namespace std;
int n,a[110];
int main(){
	cin>>n;
	for(int i = 0; i < n; i ++)cin>>a[i];
	sort(a,a+n);
	cout << a[n-1] - a[0] << endl;
	return 0;
}