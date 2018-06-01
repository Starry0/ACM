#include <bits/stdc++.h>

#include<stack>

#define ll long long
using namespace std;
const ll maxn = 1e5+10;
ll a[maxn],b[maxn];
int main()
{
    ll n,ok=1;
    ll sn=0,t=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sn+=a[i];
    }
    t = n*(n-1)/2;
    if(sn % t){
        cout<<"NO"<<endl;
        return 0;
    }
    ll ans = sn / t;
    for(int i=0;i<n&&ok;i++){
        b[i] = a[(i+1)%n]-a[i];
        if((ans-b[i])%n||ans-b[i]<0)
            ok=0;
    }
    if(ok)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
