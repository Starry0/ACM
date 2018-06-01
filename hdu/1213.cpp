#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int fa[N], t, n, m;
int find(int x) {
    return fa[x] == x ? x: find(fa[x]);
}
void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x > y) fa[x] = y;
    else fa[y] = x;
}
int main() {
    cin >> t;
    while(t--) {
        int x, y;
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) fa[i] = i;
        while(m--) {
            cin >> x >> y;
            unite(x, y);
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            if(find(i) == i) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
