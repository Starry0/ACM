// #include <iostream>
// #include <cstdio>
// using namespace std;
// const int maxn = 2e3;
// int fa[maxn*2+10];
// bool mark;
// int find(int x){
//     if(fa[x] == x)return x;
//     else return fa[x] = find(fa[x]);
// }
// void uni(int x, int y){
//     int xx, yy;
//     xx = find(x);
//     yy = find(y-maxn);
//     if(xx == yy){
//         mark = false;
//         return;
//     }
//     yy = find(y);
//     if(xx != yy) fa[xx] = fa[yy];
// }
// int main(){
//     int t, n, m, x, y, k = 1;
//     scanf("%d",&t);
//     while(t--){
//         scanf("%d%d",&n,&m);
//         for(int i = 1; i <= maxn+n; i++)fa[i] = i;
//         mark = true;
//         for(int i = 1; i <= m; i ++){
//             scanf("%d%d",&x,&y);
//             if(mark){
//                 uni(x, y+maxn);
//                 uni(y, x+maxn);
//             }
//         }
//         printf("Scenario #%d:\n", k++);
//         if(mark) printf("No suspicious bugs found!\n");
//         else printf("Suspicious bugs found!\n");
//         printf("\n");
//     }
//     return 0;
// }

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
const int MAX = 2010;
const int N = 1000010;
int a[MAX], fa[N*2];
int find(int x) {
    return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}
int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) fa[y] = x;
    else fa[x] = y;
}
int main() {
    int t, n, m;
    scanf("%d",&t);
    for(int k = 1; k <= t; k ++) {
        scanf("%d%d",&n,&m);
        for(int i = 0; i < N*2; i ++) fa[i] = i;
        bool flag = true;
        for(int i = 1; i <= m; i ++) {
            int x, y;
            scanf("%d%d",&x,&y);
            if(!flag)continue;
            x = find(x),y = find(y);
            if(x == y) flag = false;
            else {
                unite(x,N+y);
                unite(x+N,y);
            }
        }
        if(k!=1)printf("\n");
        printf("Scenario #%d:\n",k);
        if(flag) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
    }
    return 0;
}
