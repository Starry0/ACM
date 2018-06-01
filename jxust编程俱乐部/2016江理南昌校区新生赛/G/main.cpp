#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long m,n=1;
    long long s=1;
    cin>>m;
    int a[m];
    for(long long i=0;i<m;i++)
        cin>>a[i];
    for(long long i=0;i<m;i++)
        n*=a[i];
    int k[n],b=0;
    for(long long i=1;i<=n;i++)
        if(n%i==0)
            k[b++]=i;
    for(long long i=0;i<b;i++)
    {
        s*=k[i];
        s=(s%(1000000007));
    }
        cout<<s;
    return 0;
}
