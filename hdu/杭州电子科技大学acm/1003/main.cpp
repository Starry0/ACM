#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    for(int j=1;j<=t;j++){
        cin>>n;
        int sum=-1000,maxn=-1000,strat=1,send=1,a=1,b=1,m;
        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            if(sum>=0){
                b++;
                sum+=m;
            }
            else {
                a=i;
                b=i;
                sum=m;
            }
            if(maxn<sum){
                maxn=sum;
                strat=a;
                send=b;
            }
        }
        if(j==1) printf("Case %d:\n%d %d %d\n",j,maxn,strat,send);
        else printf("\nCase %d:\n%d %d %d\n",j,maxn,strat,send);
    }
    return 0;
}
