#include <iostream>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll C(ll x,ll y){
  ll ans=1;
  if(x<(y-x))
  x=y-x;
  for(ll i=x+1;i<=y;i++)
    ans*=i;
  for(ll i=1;i<=y-x;i++)
  ans/=i;
  return ans;
}
ll A(ll x,ll y){
  ll ans=1;
  for(ll i=0;i<x;i++){
    ans=ans*(y-i)%mod;
  }
  return ans;
}
int main(){
  ll n,wolf,god,human,ans=0,k=1;
  cin>>n;
  wolf=god=n/3;
  human=n-wolf-god;
  ans=((A(god-1,n-1)%mod)*(C(wolf,wolf+human)%mod)*god)%mod;
  //cout<<ans<<endl;
  k=((A(god,n-1)%mod)*(C(wolf,wolf+human-1)%mod))%mod;
  ans=(ans+k)%mod;
  //cout<<k<<endl;
  cout<<ans<<endl;
  return 0;
}
