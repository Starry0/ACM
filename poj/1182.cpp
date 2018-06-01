#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5e4+10;
int fa[N*3], n, k;
int find(int x) {
    return fa[x] == x ? fa[x]: find(fa[x]);
}
void unite(int x, int y) {
    fa[find(x)] = find(y);
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= 3*n; i ++) fa[i] = i;
    int ans = 0;
    while(k--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(0 >= x || x > n || 0 >= y || y > n || (op == 2 && x == y)) {
            ans ++;
            continue;
        }
        if(op == 1) {
            if(same(x, y+n) || same(x, y+2*n)) ans++;
            else {
                unite(x, y); unite(x+n, y+n);
                unite(x+2*n, y+2*n);
            }
        } else{
            if(same(x,y) || same(x, y+2*n)) ans++;
            else {
                unite(x, y+n); unite(x+n, y+n*2);
                unite(x+2*n, y);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
