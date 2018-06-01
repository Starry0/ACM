#include <bits/stdc++.h>
using namespace std;
int f[201];
int main()
{
    int a,b,n,i;
    while(scanf("%d%d%d",&a,&b,&n)&&a&&b&&n){
        if(n>=3){
            f[1]=1;f[2]=1;
            for(i=3;i<=200;i++){
                f[i]=(a*f[i-1]+b*f[i-2])%7;
                if(f[i-1]==1&&f[i]==1)
                    break;
            }
            //cout<<f[10]<<' '<<i-2<<endl;
            i-=2;
            n=n%i;
            if(n==0)
                printf("%d\n",f[i]);
            else printf("%d\n",f[n]);
        }
        else printf("1\n");
    }
    return 0;
}
