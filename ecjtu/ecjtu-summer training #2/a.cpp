#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1010];
int main(){
	int n, s, MAX = s,x,y;
	cin >> n >> s;
	for(int i = 0; i < n; i ++){
		cin>>x>>y;
		a[x] = max(a[x],y);
		MAX = max(x+y,MAX);
	}
	int ans = 0;
	for(int i = s; i > 0;i--){
		if(a[i] > ans){
			ans = a[i]+1;
		}else ans++;
	}
	cout << ans << endl;
	return 0;
}