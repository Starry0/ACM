#include <iostream>
#include <algorithm>
#define ll long long
const int maxn = 1e5+10;
using namespace std;

ll a[maxn],b[maxn];
int main(){
  ll n,x,k,ans1=0,ans2=0,f1=0,f2=0;
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i];
  }
  for(int i=1;i<n;i++){
    if(a[i]+a[i-1]<x){
      f1=1;
      break;
    }
    else {
      k=(a[i]+a[i-1])-x;
      ans1+=k;
      if(i<=1){
        if(k>a[1])
          a[1]=0;
        else a[1]-=k;
      }
      else
        a[i]-=k;
    }
  }
  for(int i=1;i<n;i++){
    //cout<<a[i-1]<<' '<<a[i]<<' '<<x<<endl;
    if((b[i]+b[i-1])<x){
      f2=1;
      //cout<<"zheng"<<endl;
      break;
    }
    else {
      k=(b[i]+b[i-1])-x;
      ans2+=k;
      //cout<<ans2<<endl;
      if(i==1){
        if(b[0]<k)
          b[1]=b[1]+b[0]-k;
      }
      else
        b[i]-=k;
    }
  }
  //cout<<ans1<<endl<<f1<<endl<<ans2<<endl<<f2<<endl;
  if(f1==0||f2==0){
    if(f1==0&&f2==0)
      cout<<min(ans1,ans2)<<endl;
    else if(f1==0)
      cout<<ans1<<endl;
    else if(f2==0)cout<<ans2<<endl;
  }
  else cout<<0<<endl;
  return 0;
}
