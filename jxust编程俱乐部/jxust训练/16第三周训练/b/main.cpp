#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
ll a[52];
using namespace std;

int main()
{
    a[1]=1;a[2]=2;
    for(int i=3;i<51;i++)
        a[i]=a[i-1]+a[i-2];
    int n;
   // cout<<a[7]<<" "<<a[6]<<' '<<a[5]<<endl;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n]);
    }
    return 0;
}
