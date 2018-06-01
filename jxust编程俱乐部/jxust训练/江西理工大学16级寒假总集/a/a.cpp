#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int n,k;
  while(scanf("%d%d",&n,&k)!=EOF){
    int t,ans=0;
    t=240-k;
    while(ans<n){
      if(5*(ans+1)<=t){
        ans++;t=t-ans*5;
      }
      else break;
    }
    cout<<ans<<endl;
  }
  return 0;
}
