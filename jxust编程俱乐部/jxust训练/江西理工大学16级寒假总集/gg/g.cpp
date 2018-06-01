#include <iostream>
#define ll long long
using namespace std;

const int maxn = 1e5+10;
int a[maxn];
int main(){
  ll k,n,x,ans=0;
  cin>>n>>x;
  for(int i=0;i<n;i++)
    cin>>a[i];
  if(a[0]>x){
    ans=a[0]-x;
    a[0]=x;
  }
  for(int i=1;i<n;i++){
    k=a[i]+a[i-1]-x;
    if(k>0){
      ans+=k;
      a[i]-=k;
    }
  }
  cout<<ans<<endl;
  return 0;
}
