#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], n, ans[N];
vector<int> vs;
map<int,int> mp;
int bin(int x){
	int l = 0, r = vs.size()-1;
	while(l <= r) {
		int m = (l+r) >> 1;
		if(vs[m] >= x) l = m + 1;
		else r = m -1;
	}
	return vs[r+1];
}
int main() {
	while(scanf("%d", &n)!=EOF) {
		vs.clear();
		mp.clear();
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for(int i = n; i >= 1; i --) {
			if(vs.size() == 0 || vs.back() >= a[i]) {
				vs.push_back(a[i]);
				if(!mp.count(a[i])) mp[a[i]] = i;
				ans[i] = -1;
			} else {
				int cnt = bin(a[i]);
				ans[i] = mp[cnt]-i-1;
			}
		}
		for(int i = 1; i <= n; i ++) {
			printf("%d%c",ans[i],i==n?'\n':' ');
		}
	}
	return 0;
}