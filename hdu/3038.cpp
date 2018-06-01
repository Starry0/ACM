#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int fa[N], sum[N], n, m;
int find(int x) {
    if(fa[x] == x) return x;
    int tmp = fa[x];
    fa[x] = find(fa[x]);
    sum[x] += sum[tmp];
    return fa[x];
}
void unite(int x, int y, int a, int b, int c) {
    if(x > y) {
        fa[y] = x;
        sum[y] = sum[a] - sum[b] - c;
    } else {
        fa[x] = y;
        sum[x] = sum[b] - sum[a] + c;
    }
}
int main() {
    while(cin >> n >> m) {
        for(int i = 0; i < N; i ++) {
            fa[i] = i;
            sum[i] = 0;
        }
        int ans = 0;
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            b++;
            int x = find(a), y = find(b);
            if(x == y && sum[a] != sum[b] + c) ans++;
            else if(x != y) unite(x, y, a, b, c);
        }
        cout << ans << endl;
    }
    return 0;
}
