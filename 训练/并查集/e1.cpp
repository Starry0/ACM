#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 50005
struct animal{
    int num;
    int fa;
    int relation;
} ani[MAX];
int findfa(int x){
    if(ani[x].fa==ani[x].num) return ani[x].fa;
    int temp=ani[x].fa;
    ani[x].fa=findfa(ani[x].fa);
    ani[x].relation=(ani[x].relation+ani[temp].relation)%3;
    return ani[x].fa;
}
void unionn(int x,int y,int a,int b,int d){
    ani[b].fa=a;
    ani[b].relation=(3-ani[y].relation+(d-1)+ani[x].relation)%3;
}
int main(){
    int n,k,ans=0;
    while(~scanf("%d%d",&n,&k)){
        for(int i=1; i<=n; i++){
            ani[i].num=i;
            ani[i].fa=i;
            ani[i].relation=0;
        }
        while(k--){
            int d,x,y;
            scanf("%d%d%d",&d,&x,&y);
            if(x>n||y>n){
                ans++;
                continue;
            }
            else{
                if(d == 2 && x == y) ans++;
                else{
                    int a=findfa(x);
                    int b=findfa(y);
                    if(a!=b) unionn(x,y,a,b,d);
                    else{
                        if(d == 1)if(ani[x].relation!=ani[y].relation) ans++;
                        if(d == 2)if(((ani[y].relation+3-ani[x].relation)%3)!=1) ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
