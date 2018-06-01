#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define maxn 1000000000+10
using namespace std;
long long a[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,j,n,k=0,first=0;
        scanf("%d",&n);
        memset(a,1,sizeof(a)); //0代表关灯,1代表开灯

        for(i=1;i<=n;i++)      //k个人
            for(j=1;j<=n;j++)  //n个灯
                if(j%i==0)
                    a[j]=!a[j]; //取反,0变1,1变0,原来开变关，关变开

        for(i=1;i<=n;i++) //最后输出a[i]的值就可以了
            if(a[i])
                k++; //不明白你的代码里面first是干嘛用的
    }
    return 0;
}
