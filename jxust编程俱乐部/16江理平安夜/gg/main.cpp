#include<iostream>
using namespace std;
int main()
{
    int n,i,b;
    long long m=1,k=1,mm,sn;
    cin>>n;
    b=n/3;
    for(i=1;i<=b;i++)
    {
        m=m*(n-i);
        k=k*i;
    }
    sn=b*(m/k);
    m=1;
    k=1;
       for(i=1;i<=b-1;i++)
       {
           m=m*(n-b-i);
       }
       sn=sn*m;
       m=1;
    for(i=1;i<=b;i++)
        m=m*(n-i);
    mm=m;
    m=1;
    for(i=1;i<=b;i++)
    {
        m=m*(n-b-i);
        k=k*i;
    }
    mm=mm*(m/k);
    sn=sn+mm;
    sn=sn%(1000000007);
    cout<<sn<<endl;
   return 0;
}
