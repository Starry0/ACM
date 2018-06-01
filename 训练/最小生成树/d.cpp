#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, q, fa[maxn], rank[maxn], weight, k;
void init(){
    for(int i = 0; i < maxn; i ++){
        fa[i] = i;
        rank[i] = 1;
    }
    weight = 0;
    k = 0;
}
struct Nod{
    int l, r, w;
}nod[maxn*maxn];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
void add1(int x, int y, int w){
    nod[k].l = x;
    nod[k].r = y;
    nod[k].w = w;
    k++;
}
int find(int x){
    if(x != fa[x]){
        fa[x] = find(fa[x]);
    }
    return fa[x];
    // return x = (fa[x] == x) ? x : find(fa[x]);
}
// bool uni(int x, int y){
//     int a = find(x);
//     int b = find(y);
//     if(a != b){
//         fa[a] = b;
//         return 1;
//     }
//     return 0;
// }
void kruscal(){
    sort(nod,nod+k,cmp);
    for(int i = 0; i < k; i ++){
        int xx = find(nod[i].l);
        int yy = find(nod[i].r);
        if(xx == yy) continue;
        weight += nod[i].w;
        if(rank[xx] >= rank[yy]){
            fa[yy] = xx;
            rank[xx] += rank[yy];
        }else{
            fa[xx] = yy;
            rank[yy] += rank[xx];
        }
    }
}
int main(){
        int tmp;
    while(~scanf("%d",&n)){
        init();
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j++){
                scanf("%d",&tmp);
                add1(i,j,tmp);
            }
        }
        scanf("%d",&q);
        int a, b;
        for (int i = 1; i <= q; i ++) {
            scanf("%d%d",&a,&b);
            int xx = find(a);
            int yy = find(b);
            if(rank[xx] >= rank[yy]){
                fa[yy] = xx;
                rank[xx] += rank[yy];
            }else{
                fa[xx] = yy;
                rank[yy] += rank[xx];
            }
            //uni(a,b);
        }
        kruscal();
        // for (int i = 0; i < k; i ++) {
        //     if(uni(nod[i].l,nod[i].r)){
        //         weight += nod[i].w;
        //     }
        // }
        printf("%d\n",weight);
    }
    return 0;
}
