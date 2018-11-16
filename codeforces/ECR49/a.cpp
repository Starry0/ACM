#include <bits/stdc++.h>
using namespace std;
char s[110];
bool ok(int x, int y) {
	set<char> st;
	if(s[x] == 'a') {
		st.insert('b');
	} else if(s[x] == 'z') {
		st.insert('y');
	} else {
		st.insert(s[x]+1);
		st.insert(s[x]-1);
	}
	if(s[y] == 'a') {
		if(st.count('b')) return true;
	} else if(s[y] == 'z') {
		if(st.count('y')) return true;
	} else {
		if(st.count(s[y]-1) || st.count(s[y] + 1)) return true;
	}
	return false;
}
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		bool flag = true;
		for(int i = 0; i < n/2; i ++) {
			if(!ok(i, n-i-1)) {
				flag = false;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}