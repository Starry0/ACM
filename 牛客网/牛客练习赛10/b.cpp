#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N],cnt[N], b[N];
stack<int> st;
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	cnt[n] = a[n];
	for(int i = n-1; i > 0; i --) {
		cnt[i] = max(a[i], cnt[i+1]);
	}
	int ans = 1;
	for(int i = 1; i <= n; i ++) {
		if(a[i] == cnt[i]) {
			b[ans++] = a[i];
		} else {
			st.push(a[i]);
		}
	}
	while(!st.empty()) {
		b[ans++] = st.top();
		st.pop();
	}
	for(int i = 1; i <= n; i ++) {
		printf("%d%c",b[i],i==n?'\n':' ');
	}
	return 0;
}

