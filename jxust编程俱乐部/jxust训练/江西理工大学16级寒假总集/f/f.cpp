#include <iostream>
#define ll long long
using namespace std;
int main(){
  ll a,b,x;
  ll ans1=0,ans2=0;
  cin>>a>>b>>x;
  ans1=a/x;
  ans2=b/x;
  if(ans1*x!=a)
    cout<<ans2-ans1<<endl;
  else cout<<ans2+1-ans1<<endl;
  return 0;
}
