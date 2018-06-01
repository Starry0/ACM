#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn = 51000;
struct Nod{
    int l, r;
    double w;
}nod[maxn];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
int fa[maxn], sum, k, a[770][2];
void init(){
    for(int i = 0; i < maxn; i++){
        fa[i] = i;
    }
    sum = k = 0;
}
int find(int x){
    return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}
void uni(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a != b){
        fa[a] = b;
    }
}
void kruscal(){
    for(int i = 0; i < k; i ++){
        if(find(nod[i].l) != find(nod[i].r)){
            printf("%d %d\n",nod[i].r,nod[i].l);
            uni(nod[i].r, nod[i].l);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
        init();
        for(int i = 1; i <= n; i ++){
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = i+1; j <= n; j ++){
                double d = (a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]);
                nod[k].l = i;
                nod[k].r = j;
                nod[k].w = d;
                k++;
            }
        }
        int m;
        scanf("%d",&m);
        for(int i = 0; i < m; i ++){
            int tmp, tmp1;
            scanf("%d%d",&tmp,&tmp1);
            uni(tmp,tmp1);
        }
        sort(nod,nod+k,cmp);
        kruscal();
    return 0;
}
