#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
int x[N], y[N], d[N];
int dis(int x1, int y1, int x2, int y2) {
	return abs(x1-x2)+abs(y1-y2);
}
int main() {
	int n, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i <= n+1; i ++) cin >> x[i] >> y[i];
		memset(d, -1, sizeof(d));
		d[0] = 1000;
		queue<int> que;
		que.push(0);
		while(que.size()) {
			int v = que.front(); que.pop();
			for(int i = 1; i <= n; i ++) {
				if(dis(x[v],y[v],x[i],y[i]) <= d[v]) {
					int tmp = d[v] - dis(x[v],y[v],x[i],y[i]);
					if(tmp%50 == 0) tmp = 1000;
					else tmp = 950+tmp%50;
					if(tmp > d[i]) {
						d[i] = tmp; 
						que.push(i);
					}
				}
			}
		}
		bool flag = false;
		for(int i = 0; i <= n; i ++) {
			if(d[i] != -1 && dis(x[i],y[i],x[n+1],y[n+1]) <= d[i]) {
				flag = true;
				break;
			}
		}
		if(flag) printf("happy\n");
		else printf("sad\n");
	}
	return 0;
}