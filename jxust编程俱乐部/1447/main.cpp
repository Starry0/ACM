#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int a[1000],b[1000];
int main()
{
    memset(a,0,sizeof(a));
    ll a,b,ans=0;
    a[0]=0;
    scanf("%lld%lld",&a,&b);
    for(int i=a;i<=b;i++){
        for(int j=a;j<=b;j++){
            if((a*a+b*b)*i*j<=a*b*(i*i+j*j)){
              //  a[0]=1;
              //  b[0]=1;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    for(ll i=0;i<ans;i++){
        cout<<a[i]<<' '<<b[i]<<endl;
    }
    return 0;
}
