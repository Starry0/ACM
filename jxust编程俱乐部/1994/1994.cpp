#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int prime(ll x){
  if(x==2)
    return 1;
  else {
    for(int i=2;i<=sqrt(x);i++){
      if(x%i==0){
        return 0;
      }
    }
  }
  return 1;
}
ll a[10011];
int main(){
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a,a+n);
  ll m=a[n-k]-a[k-1];
  if(m<2)
    cout<<"NO"<<endl;
  else {
    if(prime(m))
      cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  cout<<m<<endl;
  return 0;
}
