#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 2e3+10;
int edge[N][N], vis[N], match[N];
int n, k, v, u;

bool dfs(int v) {
    for(int i = n; i < 2*n; i ++) {
        if(edge[v][i] && !vis[i]) {
            vis[i] = 1;
            if(match[i] == -1 || dfs(match[i])) {
                match[i] = v;
                return true;
            }
        }
    }
    return false;
}
int max_match() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int i = 0; i < n; i ++) {
        if(match[i] < 0) {
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) res++;
        }
    }
    return res;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> k;
		for(int j = 0; j < k; j ++) {
			cin >> v;
			edge[i][v+n] = 1;
		}
	}
	cout << n-max_match() << endl;
	return 0;
}