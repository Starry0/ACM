#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	int minn = a[0];
	int maxn = a.back();
	if(minn == maxn){
		if(minn*2 <= n || minn == n-1) ans = 1;
	}
	if(maxn == minn +1 ){
		int cnt = 0;
		for(int i = 0; a[i] == minn; i++) cnt++;
		if(maxn > cnt && cnt + 2*(maxn-cnt) <= n) ans = 1;
	}
	printf("%s\n",ans?"Yes":"No");
	return 0;
}