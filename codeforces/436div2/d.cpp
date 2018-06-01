#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N], b[N];
map<int,int> mp;
set<int> st;
int main()  {
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		mp[a[i]] ++;
	}
	int cnt = 1;
	for(int i = 1; i <= n; i ++) {
		if(mp[a[i]] == 1) {
			b[i] = a[i];
		} else {
			while(mp.count(cnt)) cnt++;
			if(cnt > a[i]) {
				if(st.count(a[i])) {
					b[i] = cnt;
					cnt++;
					ans++;
				} else {
					st.insert(a[i]);
					b[i] = a[i];
				}
			} else {
				b[i] = cnt;
				mp[a[i]] --;
				cnt++;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	for(int i = 1; i <= n; i ++) printf("%d%c",b[i],i==n?'\n':' ');
	return 0;
}