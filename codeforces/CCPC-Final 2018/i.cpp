#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
typedef pair<int,int> P;
set<P> st, st1, st2;
map<int, int> X, Y;
map<int,vector<int> , greater<int> > mp;
map<int,vector<int> , greater<int> > ::iterator it;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, m, x, y;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			cin >> x >> y;
			X[x]++;
			Y[y]++;
			st.insert(P(x,y));
		}
		for(auto it : Y) {
			mp[it.second].push_back(it.first);
		}
		it = mp.begin();
		int cnt1 = it->first;
		vector<int> v1 = it->second;
		int cnt2 = 1e6;
		vector<int> v2;
		if(mp.size() != 1) {
			cnt2 = (++it)->first;
			v2 = it->second;
		}
		int MAX = 0, cnt = 0;
		



		
		X.clear();Y.clear();
		mp.clear();
		st.clear();
	}
	return 0;
}