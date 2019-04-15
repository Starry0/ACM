// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int N = 2e5+10;
// vector<int> vs[N], pre[N];
// int fa[N], n, v, u, x1, x2, x3;
// int main() {
// 	cin >> n;
// 	for(int i = 1; i <= n; i ++) {
// 		cin >> v >> u;
// 		vs[i].push_back(v);vs[i].push_back(u);
// 		pre[u].push_back(i);pre[v].push_back(i);
// 	}
// 	for(int i = 1; i <= n; i ++) {
// 		x1 = pre[i][0], x2 = pre[i][1];
// 		if(vs[x1][0] == x2 || vs[x1][1] == x2) {
// 			fa[x1] = x2;
// 			fa[x2] = i;
// 			fa[i] = (vs[x2][0]==i)?vs[x2][1]:vs[x2][0];
// 		}
// 	}
// 	int x = 1;
// 	for(int i = 1; i <= n; i ++) {
// 		printf("%d ",x);
// 		x = fa[x];
// 	}
// 	return 0;
// }


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
vector<int> vs[N], v[N];
bool vis[N];
int main() {
	int n, u, vv;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> u >> vv;
		vs[i].push_back(u);
		vs[i].push_back(vv);
	}
	if(n == 3) return 0*printf("1 2 3\n");
	int x = 1;
	for(int i = 1; i <= n; i ++) {
		printf("%d ",x);
		int x1 = vs[x][0], x2 = vs[x][1];
		if(vs[x1][0] == x2 || vs[x1][1] == x2) {
			x = x1;
		} else {
			x = x2;
		}
	}
	return 0;
}