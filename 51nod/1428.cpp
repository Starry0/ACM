/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct Nod {
	int l, r;
}nod[N];
int vis[N*2];
set<int> st;
map<int,int> mp;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> nod[i].l >> nod[i].r;
		st.insert(nod[i].l);
		st.insert(nod[i].r);
	}
	int ans = 0;
	set<int>::iterator it = st.begin();
	for(; it != st.end(); it ++) {
		mp[(*it)] = ans++;
	}
	for(int i = 0; i < n; i ++) {
		for(int j = mp[nod[i].l]; j < mp[nod[i].r]; j ++) {
			vis[j]++;
		}
	}
	ans = 0;
	for(int i = 0; i < 2*N; i ++) {
		ans = max(ans,vis[i]);
	}
	cout << ans << endl;
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct Nod {
	int l, r;
}nod[N];
int n;
bool cmp(Nod &a, Nod &b) {
	return a.l < b.l;
}
int main() {
	priority_queue<int,vector<int>, greater<int> >que;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> nod[i].l >> nod[i].r;
	}
	sort(nod,nod+n,cmp);
	que.push(nod[0].r);
	int ans = 1;
	for(int i = 1; i < n; i ++) {
		if(nod[i].l >= que.top()) {
			que.pop();
			que.push(nod[i].r);
		} else que.push(nod[i].r);
		int MAX = que.size();
		ans = max(ans,MAX);
	}
	cout << ans << endl;
	return 0;
}