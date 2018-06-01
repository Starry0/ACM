#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int k=0,q=1,a,b,c;
        for(int i=n;i<=m;i++){
            a=i%10;b=(i/10)%10;c=i/100;
            if(i==(a*a*a+b*b*b+c*c*c)){
                if(q){
                    printf("%d",i);
                    k++;
                    q=0;
                }
                else {
                    printf(" %d",i);
                    k++;
                }
            }
        }
        if(k)printf("\n");
        else printf("no\n");
    }
    return 0;
}
