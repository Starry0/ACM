#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5+10;
int fa[N*2], t, n, m;
char str[3];
int x, y;
int find(int x) {
    return fa[x] == x ? x: find(fa[x]);
}
void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x < y) fa[y] = x;
    else fa[x] = y;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i ++) {
            fa[i] = i;
            fa[i+N] = i+N;
        }
        while(m--) {
            scanf("%s%d%d",str,&x,&y);
            if(str[0] == 'A') {
                if(find(x) == find(y+N)) printf("In different gangs.\n");
                else if(find(x) == find(y)) printf("In the same gang.\n");
                else printf("Not sure yet.\n");
            } else{
                unite(x,y+N);
                unite(x+N,y);
            }
        }
    }
    return 0;
}
