#include <iostream>
#define ll long long
using namespace std;
const int mod = 1e9+7;
int main()
{
    int n;
    ll ans=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
