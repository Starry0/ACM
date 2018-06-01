#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m,i,sn=0;
    while(scanf("%d",&m)!=EOF){
        for(i=1;i<=m;i++)
            sn+=i;
        printf("%d\n\n",sn);
        sn=0;
    }
    return 0;
}
