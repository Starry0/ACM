#include <bits/stdc++.h>
using namespace std;
const int N = 33;
std::vector<int> vs[N];
int fa[N];
int find(int x) {
    return fa[x] == x? x : find(fa[x]);
}
void unit(int x, int y) {
    x = find(x), y = find(y);
    if(x < y) fa[x] = y;
    else fa[y] = x;
}
void init() {
    for(int i = 0; i < N; i ++) {
        vs[i].clear();
        fa[i] = i;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        init();
        cin >> n >> m;
        for(int i = 0; i < m; i ++) {
            int u, v;
            cin >> u >> v;
            unit(u,v);
            vs[u].push_back(v);
            vs[v].push_back(u);
        }
        int ans = 0, ans1 = 0;
        for(int i = 1; i <= n; i ++) {
            if(vs[i].size()%2) ans++;
            if(find(i) == i) ans1++;
        }
        if(ans <= 2 && ans1 == 1) printf("Zhen\n");
        else printf("Xun\n");
    }
    return 0;
}
