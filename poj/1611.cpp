#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 30010;
int fa[N];
int find(int x) {
    return fa[x] == x ? x: find(fa[x]);
}
void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x > y) fa[x] = y;
    else fa[y] = x;
}
int main() {
    int n, m;
    while(cin >> n >> m, n) {
        for(int i = 0; i < n; i ++) fa[i] = i;
        while(m--) {
            int a, b, c;
            scanf("%d%d",&a,&b);
            for(int i = 0; i < a-1; i ++) {
                scanf("%d",&c);
                unite(b,c);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) if(find(i) == 0) ans++;
        cout << ans << endl;
    }
    return 0;
}
