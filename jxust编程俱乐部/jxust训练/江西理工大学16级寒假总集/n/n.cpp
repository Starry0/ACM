#include <iostream>
#include <cstdio>
#define ll long long
const int maxn = 1e5+10;
using namespace std;

ll arr[maxn];
int main(){
  ll n,a,b,ans=0;
  cin>>n>>a>>b;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    //scanf("%lld",&a[i]);
  }
  for(int i=0;i<n-1;i++){
    if((arr[i+1]-arr[i])*a>=b)
      ans+=b;
    else ans+=((arr[i+1]-arr[i])*a);
  }
  cout<<ans<<endl;
  return 0;
}
