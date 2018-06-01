#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n;
int a[N], sum[N], pre[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = sum[i-1] + (a[i] == 1);
	}
	for(int i = n; i >= 1; i --) pre[i] = pre[i+1] + (a[i]==2);
	int MAX = 0;
	for(int i = 1; i <= n; i ++) {
		int ans1 = 0, ans2 = 0;
		for(int j = 1; j <= i; j ++) {
			ans1 = max(ans1,sum[j]+pre[j]-pre[i+1]);
		}
		for(int j = i+1; j <= n; j ++) {
			ans2 = max(ans2, sum[j]-sum[i]+pre[j]);
		}
		MAX = max(MAX,ans1+ans2);
	}
	cout << MAX << endl;
	return 0;
}

//1 1 2 2 2 2 2 1 1 2 2 1 2 1 2 2 2 1 1 1 2 1 1 2 2 2 
//2 1 2 2 1 2 1 2 1 2 2 1 2 2 2 2 2 2 1 2 2 1 2 2 2 1 
//1 1 1 2 1 1 2 2 2 1 1 1 2  52