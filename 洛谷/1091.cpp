#include <bits/stdc++.h>
using namespace std;
int a[110], n;
int dp[110], dp1[110];
int main() {
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
	for(int i = n-1; i >= 0; i --){
        dp1[i] = 1;
        for(int j = n-1; j > i; j --){
            if(a[i] > a[j]){
                dp1[i] = max(dp1[i],dp1[j]+1);
            }
        }
    }
	int MAX = 0;
	for(int i = 0; i < n; i ++) {
		MAX = max(MAX,dp[i]+dp1[i]);
	}
	cout << n-MAX+1 << endl;
	return 0;
}
