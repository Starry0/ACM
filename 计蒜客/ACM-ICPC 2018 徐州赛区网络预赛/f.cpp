#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef pair<int,int> P;
map<P,int> mp[2];
int main() {
	int t, n, k, x, y;
	scanf("%d", &t);
	while(t--) {
		mp[1].clear(); mp[0].clear();
		scanf("%d", &n);
		int MAX = 0, last = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &k);
			last = 1 - last;
			for(int j = 1; j <= k; j ++) {
				scanf("%d%d", &x, &y);
				if(!mp[1-last].count(P(x,y))) {
					mp[last][P(x,y)] = 1;
				} else {
					mp[last][P(x,y)] = mp[1-last][P(x,y)] + 1;
				}
				MAX = max(MAX, mp[last][P(x,y)]);
			}
			mp[1-last].clear();
		}
		printf("%d\n",MAX);
	}
	return 0;
}