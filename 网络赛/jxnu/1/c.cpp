#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Nod{
    int id;
    char s[25];
    int k[110];
    int sum;
    int flag;
};
int n,m;
bool cmp(Nod a, Nod b){
    if(a.sum != b.sum) return a.sum > b.sum;
    else return a.id < b.id;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        Nod nod[n+1];
        for(int i = 0; i < n; i ++){
            scanf("%d%s",&nod[i].id ,nod[i].s);
            nod[i].sum = 0;
            for(int j = 0; j < m; j ++){
                scanf("%d",&nod[i].k[j]);
                nod[i].sum += nod[i].k[j];
            }
        }
        sort(nod, nod+n,cmp);
        nod[0].flag = 1;
        for(int i = 1; i < n; i ++){
            if(nod[i].sum == nod[i-1].sum){
                nod[i].flag = nod[i-1].flag;
            }else{
                nod[i].flag = i + 1;
            }
        }
        for(int i = 0; i < n; i ++){
            printf("%d %s ",nod[i].id,nod[i].s);
            for(int j = 0; j < m; j ++){
                printf("%d ",nod[i].k[j]);
            }
            printf("Sum = %d Ranking = %d\n",nod[i].sum,nod[i].flag);

        }
    }
    return 0;
}
