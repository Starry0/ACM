#include <iostream>
#define ll long long
using namespace std;
ll f(int x,int y){
    ll sn = 1;
    if(x<(y-x))x=y-x;
    for(int i=x;i<=y;i++)
        sn*=i;
    for(int i=1;i<=y-x;i++)
        sn/=i;
    return sn;
}

int main()
{
    int n,m,k;
    ll ans = 0;
    cin>>n>>k>>m;
    ans = n / m;
    ans += f(int(k-ans),int(n-ans));
    cout<<ans<<endl;
    return 0;
}
