#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1000010;
int fa[N], MAX[N];
vector<int> vs[N];
void dfs(int v) {
	
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", &a, &b);
		vs[a].push_back(b);
		vs[b].push_back(a);
	}
    return 0;
}
