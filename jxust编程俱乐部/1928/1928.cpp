#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

ll f(ll x){
  ll ans=0,a;
  while(x>0){
      a=x%10;
      ans=ans*10+a;
      x/=10;
  }
  return ans;
}
int fz(ll x){
  if(x==f(x))
    return 1;
  return 0;
}
int main(){
  int n,t,a;
  cin>>t;
  while(t--){
    scanf("%d",&n);
    int i=1 ;
    a=f(n);//cout<<a<<endl;
    n=a+n;
    while(fz(n)==0){
      a=f(n);//cout<<a<<endl;
      n+=a;
      i++;
      if(i>8){
        break;
      }
    }
    if(i<=8)
      cout<<i<<endl;
    else cout<<0<<endl;
  }
  return 0;
}
