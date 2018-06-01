#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int> G[N];

double dfs(int v, int p) {
    double ans = 0;
    int len = 0;
    for(int i = 0; i < G[v].size(); i ++) {
        int u = G[v][i];
        if(u == p) continue;
        ans += (1 + dfs(u, v));
        len ++;
    }
    return len == 0 ? 0.0 : ans / len;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    printf("%.15f\n",dfs(1,0));
    return 0;
}
