#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, x;
const int N = 1000010;
int vis[N];
vector<int> vs;
bool bin(int x) {
	int l = 1, r = n;
	while(l <= r) {
		int m = (l+r) >> 1;
		if(vis[m] == x) return true;
		else if(vis[m] > x) r = m-1;
		else l = m+1;
	}
	return false;
}
int main() {
	while(cin >> n >> m) {
		vs.clear();
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &vis[i]);
		}
		for(int i = 1; i <= m; i ++) {
			scanf("%d", &x);
			if(bin(x)) vs.push_back(x);
		}
		if(vs.empty()) printf("empty\n");
		else {
			for(int i = 0, len = vs.size(); i < len; i ++) {
				printf("%d%c",vs[i],(i==len-1)?'\n':' ');
			}
		}
	}
	return 0;
}