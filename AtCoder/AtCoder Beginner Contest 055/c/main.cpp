#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n,m;
    cin>>n>>m;
    ll ans = 0;
    if(n*2<=m){
        ans=n;
        m=m-n*2;
        ans+=m/4;
    }
    else{
        ans = m/2;
    }
    cout<<ans<<endl;
    return 0;
}
