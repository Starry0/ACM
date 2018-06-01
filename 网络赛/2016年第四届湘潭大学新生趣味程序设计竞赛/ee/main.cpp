#include<bits/stdc++.h>
using namespace std;
int x[100000],y[100000];
int sum[100000+100000];
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<m;i++)
        {
            sum[n+i]=x[n];
        }
        for(int i = n; i >= 0; i--)
        {
            int Min =(1<<31)-1;
            for(int j = 1; j <= m; j++)
            {
                Min=min(Min,sum[i+j]+x[i]);
            }
            sum[i]=Min;
        }
        printf("%d\n",sum[0]);

    }
    return 0;
}
