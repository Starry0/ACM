#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n,b[]={6,8,4,2};
    cin>>n;
    ll a=n%4;
    if(n==0)
        cout<<1<<endl;
    else cout<<b[a]<<endl;
    return 0;
}
