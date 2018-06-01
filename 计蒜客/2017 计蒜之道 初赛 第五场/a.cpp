#include <bits/stdc++.h>

using namespace std;
int a[110];
bool cmp(int a, int b){
	return a>b;
}
int sum(int x){
	int ans = 0;
	for(int i = 0; i < x; i ++){
		if((i !=0 && a[i] <= 0) || (a[i] == 0)) break;
		ans += a[i];
	}
	return ans-x+1;
}
int main()
{
	int n, m;
	cin>>n>>m;
	if(n==0 || n == 1){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < m; i ++) cin >> a[i];
	sort(a,a+m,cmp);
	for(int i = 1; i <= m; i ++){
		if(sum(i) >= n){
			cout << i << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
	return 0;
}