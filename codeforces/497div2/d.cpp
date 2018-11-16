#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, a, b, c, t;
int x[N];
std::vector<int> v[N];
std::vector<int>::iterator it;
int main() {
	int t;
	for(int i = 2; i <= N; i ++) {
		for(int j = i+i; j < N; j += i) {
			x[j] ++;
			v[j].push_back(i);
		}
	}
	cin >> t;
	while(t--) {
		scanf("%d%d%d", &a, &b, &c);
		int ans = x[a]*x[b]*x[c];
		int ans2 = 0, ans3 = 0;
		for(int i = 0; i < v[a].size(); i ++) {
			int cnt = 0;;
			it = lower_bound(v[b].begin(), v[b].end(), v[a][i]);
			if(it != v[b].end() && (*it) == v[a][i]) cnt++;
			it = lower_bound(v[c].begin(), v[c].end(), v[a][i]);
			if(it != v[c].end() && (*it) == v[a][i]) cnt++;
			if(cnt == 1) ans2++;
			else if(cnt == 2) ans3++;
		}
		
		int ans4 = 0;
		for(int i = 0; i < v[b].size(); i ++) {
			int cnt = 0;;
			it = lower_bound(v[a].begin(), v[a].end(), v[b][i]);
			if(it != v[b].end() && (*it) == v[a][i]) continue;
			it = lower_bound(v[c].begin(), v[c].end(), v[b][i]);
			if(it != v[c].end() && (*it) == v[a][i]) cnt++;
			if(cnt == 1) ans2++;
			else if(cnt == 2) ans3++;
		}
	}
	return 0;
}

