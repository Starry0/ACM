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
        memset(a,1,sizeof(a)); //0����ص�,1������

        for(i=1;i<=n;i++)      //k����
            for(j=1;j<=n;j++)  //n����
                if(j%i==0)
                    a[j]=!a[j]; //ȡ��,0��1,1��0,ԭ������أ��ر俪

        for(i=1;i<=n;i++) //������a[i]��ֵ�Ϳ�����
            if(a[i])
                k++; //��������Ĵ�������first�Ǹ����õ�
    }
    return 0;
}
