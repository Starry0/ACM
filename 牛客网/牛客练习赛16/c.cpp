#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int fa[N];
struct Nod{
    bool visx[N*10], visy[10*N];
    Nod() {
        memset(visx, 0, sizeof(visx));
        memset(visy, 0, sizeof(visy));
    }
}nod[N];
int find(int x) {
    return fa[x] == x ? x: find(fa[x]);
}
void unit(int x, int y) {
    x = find(x), y = find(y);
    if(x > y) fa[x] = y;
    else fa[y] = x;
}
int main() {
    int n, ans = 0, x, y;
    for(int i = 0; i <= 100; i ++) fa[i] = i;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> x >> y;
        for(int j = 0; j < i; j ++) {
            if(nod[j].visx[x] || nod[j].visy[y]) unit(i,j);
        }
        nod[i].visx[x] = true;
        nod[i].visy[y] = true;
    }
    for(int i = 0; i < n; i ++) {
        if(i == find(i)) ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}
