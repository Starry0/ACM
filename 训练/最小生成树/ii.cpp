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
int fa[maxn], k;
void init(){
    for(int i = 0; i < maxn; i++){
        fa[i] = i;
    }
    k = 0;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
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
        long long sum = 0;
        sort(nod,nod+k,cmp);
        for(int i = 0; i < k; i ++){
            int a = fa[nod[i].r];
            int b = fa[nod[i].l];
            if(a != b){
                sum += nod[i].w;
                for(int i = 0; i < n; i ++){
                    if(fa[i] == a){
                        fa[i] = b;
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
