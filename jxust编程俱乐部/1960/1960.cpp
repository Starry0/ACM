#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int f(ll x){
  if(x<2)
    return 0;
  for(ll i=2;i<=sqrt(x);i++){
    if(x%i==0)
      return 0;
  }
  return 1;
}
int main(){
  ll x;
  cin>>x;
  if(f(x))
    cout<<"Y"<<endl;
  else cout<<"N"<<endl;
  return 0;
}
