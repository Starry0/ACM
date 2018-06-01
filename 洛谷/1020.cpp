#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 100010;
int a[N];
int dp[N];
int main() {
	int n = 0;
	while(cin>>a[n]) {
		 a[n] = -a[n];
		n++;
	}
	for(int i = 0; i < n; i ++) {
		*upper_bound(dp,dp+n,a[i]) = a[i];
	}
	printf("%d\n",lower_bound(dp,dp+n,0)-dp);
	memset(dp,INF,sizeof(dp));
	for(int i = 0; i < n; i ++) {
		a[i] = -a[i];
	}
	for(int i = 0; i < n; i ++) *lower_bound(dp,dp+n,a[i]) = a[i];
	printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
	return 0;
}
/*
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 100010;
int a[MAX], dp[MAX];
int main(){
	int n = 0;
	while(cin>>a[n]) {
		a[n] = -a[n];
		n++;
	}
    int res = 0;
    for(int i = 0; i < n; i ++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++){
            if(a[j] <= a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        res = max(dp[i],res);
    }
    printf("%d\n",res);
	for(int i = 0; i < n; i ++) a[i] = -a[i];
	res = 0;
    for(int i = 0; i < n; i ++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        res = max(dp[i],res);
    }
    printf("%d\n",res);
    return 0;
}
*/