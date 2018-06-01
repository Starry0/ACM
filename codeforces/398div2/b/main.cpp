#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi (4*atan(1.0))
#define eps 1e-14
#define bug(x,y) cout<<"bug"<<x<<" "<<y<<endl;
const int N=1e5+10,M=1e6+10,inf=2e9+10,mod=1e9+7;
const ll INF=1e18+10;
ll a[N];
map<ll,int>mp;
int main()
{
    ll ts,tf,t,n;
    cin>>ts>>tf>>t>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]]=1;
    ll ans=a[1]-1;
    ll st=ts;
    for(int i=1;i<=n;i++)
    {
        if(ts>tf)break;
        if(a[i]<=ts)
            ts+=t;
        else
        {
            cout<<ts<<endl;
            return 0;
        }
    }
    if(tf-ts>=t){
        cout<<ts<<endl;
        return 0;
    }
    ll wait=INF;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=0||mp[a[i]-1])continue;
        if(st+(i-1)*t<=tf&&wait>st+(i-1)*t-a[i]+1)
        {
            wait=st+(i-1)*t-a[i]+1;
            ans=a[i]-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
