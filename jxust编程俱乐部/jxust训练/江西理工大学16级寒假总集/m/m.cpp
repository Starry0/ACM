#include <iostream>
#include <cmath>
#include <map>
#define ll long long
const int mod = 1e9+7;
using namespace std;
map<int,int>m;
void fcount(ll x){
  ll i=2;
  while(x>1){
    if(x%i==0){
      while(x%i==0){
        m[i]++;
        x/=i;
      }
    }
    i++;
  }//cout<<"1"<<endl;
}
ll shu(){
  ll ans=1;
  map<int,int>::iterator it;
  for(it = m.begin();it!=m.end();++it){
    //cout<<(*it).first<<' '<<(*it).second<<endl;
    ans=(ans%mod*((*it).second+1))%mod;
  }
  return ans;
}
int main(){
  int n;
  ll sum=1,ans=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    fcount(i);
  }
  //cout<<sum<<endl;
  cout<<shu()<<endl;
  return 0;
}
