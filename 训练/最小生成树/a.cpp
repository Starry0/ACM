#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100;
int n, fa[maxn], k, weight;

struct Nod{
    int l, r, w;
}nod[maxn];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
void init(){
    for(int i = 0; i < maxn; i ++){
        fa[i] = i;
    }
    weight = k = 0;
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
    for(int i = 0; i < k; i ++){
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
        char c;
        int a, b, m;
        for(int i = 1; i < n; i ++){
            cin >> c >> m;
            //scanf("%c%d",&c,&m);
            a = c - 'A';
            while(m--){
                //scanf("%c%d",&c,&b);
                cin >> c >> b;
                nod[k].l = a;
                nod[k].r = c-'A';
                nod[k].w = b;
                k++;
            }
        }
        sort(nod, nod+k,cmp);
        kruscal();
    }
    return 0;
}
