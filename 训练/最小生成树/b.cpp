#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1100;

int n, cnt, fa[maxn], weight;

void init(){
    for(int i = 0; i < maxn; i ++){
        fa[i] = i;
    }
    weight = 0;
}

struct Nod{
    int l, r, w;
}nod[maxn];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
int find(int x){
    return x = (fa[x] == x)? x : find(fa[x]);
}
void uni(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a != b){
        fa[a] = b;
    }
}
void kruscal(){
    sort(nod, nod+cnt, cmp);
    for(int i = 0; i < cnt; i ++){
        if(find(nod[i].l) != find(nod[i].r)){
            weight += nod[i].w;
            uni(nod[i].l, nod[i].r);
        }
    }
    printf("%d\n",weight);
}
int main(){
    while(~scanf("%d",&n)&&n){
        init();
        scanf("%d",&cnt);
        for(int i = 0; i < cnt; i ++) {
            scanf("%d%d%d",&nod[i].l,&nod[i].r,&nod[i].w);
        }
        //sort(nod, nod+cnt, cmp);
        kruscal();
    }
}
