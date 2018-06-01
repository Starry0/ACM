#include<iostream>
#include<cmath>
using namespace std;
long long a[10000][10000],N,M,k,i,j;
long long x[1010],y[1010],z[1010],count;
const int mod=1e10;
int main()
{
    while(cin>>N>>M)
    {
       count=M;
       for(i=1;i<=N;i++)
        {
           for(j=1;j<=N;j++)
           {
               a[i][j]=mod;
               if(i==j) a[i][j]=0;
           }
        }
       for(i=1;i<=M;i++)
       {
           cin>>x[i]>>y[i]>>z[i];
           a[x[i]][y[i]]=z[i];
           a[y[i]][x[i]]=z[i];
       }
       for(k=1;k<=N;k++)
       {
           for(i=1;i<=N;i++)
           {
               for(j=1;j<=N;j++)
               {
                   a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
               }
           }
       }
       for(i=1;i<=M;i++)
       {
           k=0;
           for(j=1;j<=N;j++)
           {
               if(a[j][x[i]]+z[i]==a[j][y[i]])
                k=1;
           }
           if(k==1) count--;
       }
       cout<<count<<endl;
    }
    return 0;
}
