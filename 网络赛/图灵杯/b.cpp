#include <bits/stdc++.h>
using namespace std;
int a[11];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	int t, k;
	cin >> t;
	for(int i = 1; i <= t; i ++){
		cin >> k;
		for(int j = 0; j < 10; j ++) cin >> a[j];
		sort(a,a+10,cmp);
		cout << k << ' ';
		int flag = 1;
		for(int j = 1; j < 10; j ++){
			if(a[j]==a[j-1])continue;
			flag++;
			if(flag == 3){
				cout << a[j] << endl;
			}
		}
	}
	return 0;
}