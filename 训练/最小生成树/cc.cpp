#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 1100;
struct Nod{
    int l, r;
    double w;
}nod[maxn*maxn];
bool cmp(Nod a, Nod b){
    return a.w < b.w;
}
int k, fa[maxn];
double sum,da[110][4];
void init(){
    for(int i = 0; i < maxn; i ++){
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
            sum += nod[i].w;
            uni(nod[i].l, nod[i].r);
        }
    }
    printf("%.3lf\n",sum);
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        init();
        for (int i = 0; i < n; i ++) {
            cin>>da[i][0]>>da[i][1]>>da[i][2]>>da[i][3];
        }
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                double r = ((da[i][0]-da[j][0])*(da[i][0]-da[j][0])
                            +(da[i][1]-da[j][1])*(da[i][1]-da[j][1])
                            +(da[i][2]-da[j][2])*(da[i][2]-da[j][2]));
                double d = sqrt(r) - (da[i][3]+da[j][3]);
                nod[k].l = i;
                nod[k].r = j;
                if(d < 0.0000001){
                    nod[k].w = 0;
                }
                else nod[k].w = d;
                k++;
            }
        }
        sort(nod,nod+k,cmp);
        //double sum = 0.0;
        kruscal();
        // for(int i = 0; i < k; i ++){
        //     int m1 = fa[nod[i].l];
        //     int m2 = fa[nod[i].r];
        //     if(m1 != m2){
        //         sum += nod[i].w;
        //         for(int j = 0; j < n; j ++){
        //             if(fa[j] == m1){
        //                 fa[j] = m2;
        //             }
        //         }
        //     }
        // }
        // printf("%.3lf\n",sum);
    }
    return 0;
}
