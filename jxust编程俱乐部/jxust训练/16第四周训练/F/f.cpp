#include <iostream>
#include <map>
#define ll long long
#define pi 3.14a
#define mod 1000000007
//const int mod=1e9+7;
using namespace std;
map<int,int>m;
int an[100010];
int main(){
  int n,a;
  ll ans=1;
  cin>>n;
  if(n%2!=0){
    for(int i=1;i<=n;i++){
      cin>>a;
      m[a]++;
      if(m[a]==3||m[0]==2||a%2!=0){
        cout<<0<<endl;
        return 0;
      }
    }
    for(int i=1;i<=n/2;i++){
      ans=ans*2%mod;
    }
  }
  else {
    for(int i=0;i<n;i++){
      cin>>a;
      m[a]++;
      if(m[a]==3||a%2==0){
        cout<<0<<endl;
        return 0;
      }
    }
    for(int i=1;i<=n/2;i++){
      ans=ans*2%mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}
