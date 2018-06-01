#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 11000;
struct Nod{
    int l, r, w;
}nod[maxn];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
int fa[maxn], sum, k;
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
    if(a != b) fa[a] = b;
}
void kruscal(){
    for(int i = 0; i < k; i ++){
        if(find(nod[i].r) != find(nod[i].l)){
            sum += nod[i].w;
            uni(nod[i].r, nod[i].l);
        }
    }
    cout << sum << endl;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        int tmp;
        init();
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                scanf("%d",&tmp);
                if(i > j){
                    nod[k].l = i;
                    nod[k].r = j;
                    nod[k].w = tmp;
                    k++;
                }
            }
        }
        sort(nod,nod+k,cmp);
        kruscal();
    }
}
