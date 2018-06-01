#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e5+10;
int a[MAX_N];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin>>a[i];
	int ans = 0, flag = 0;
	for(int i = 1; a[i] != i; i = a[i]){;
		ans++;
		if(a[i] == 2){
			flag = 1;
			break;
		}
		if(ans > n)break;
	}
	if(flag) cout<< ans << endl;
	else cout << -1 << endl;
	return 0;
}