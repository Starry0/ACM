#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn = 101000;
int k, sum, n, p, fa[maxn], a[maxn];
struct Nod{
    int l, r;
    double w;
}nod[maxn];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
void init(){
    for(int i = 1; i < maxn; i ++){
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
        if(find(nod[i].l) != find(nod[i].r)){
            sum += nod[i].w;
            uni(nod[i].l, nod[i].r);
        }
    }
    printf("%d\n",sum);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        for(int i = 1; i <= n; i ++){
            scanf("%d",&a[i]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                int tmp;
                // scanf("%d",tmp);
                cin >> tmp;
                if(i > j){
                    nod[k].l = i;
                    nod[k].r = j;
                    nod[k].w = a[i] + a[j] + tmp;
                    k++;
                }
            }
        }
        //cout << sum << endl;
        sort(nod,nod+k,cmp);
        kruscal();
    }
    return 0;
}
