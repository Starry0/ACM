#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<pair<int,int> > vs[N];
priority_queue<pair<int, int> > que;
int main() {
	int n, t;
	cin >> n >> t;
	for(int i = 1; i <= n; i ++) {
		int x, y;
		cin >> x >> y;
		vs[x].push_back(make_pair(y,i));
	}
	int sum = 0;
	for(int i = n; i >= 0; i --) {
		for(int j = 0; j < vs[i].size(); j ++) {
			que.push(vs[i][j]);
			sum += vs[i][j].first;
		}
		while(que.size() > i) {
			sum -= que.top().first;
			que.pop();
		}
		if(que.size() == i && sum <= t) {
			printf("%d\n%d\n",i,i);
			while(!que.empty()) {
				printf("%d ",que.top().second);
				que.pop();
			}
			printf("\n");
			break;
		}
	}
	return 0;
}
/*
5 300
3 100
4 150
4 80
2 90
2 300
*/