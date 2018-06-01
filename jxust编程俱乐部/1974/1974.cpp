#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;
ll f(int m,int n){
  if(m<n-m)
    m=n-m;
  ll ans =1;
  for(int i=m+1;i<=n;i++)
    ans*=i;
  for(int i=n-m;i>0;i--)
    ans/=i;
  return ans;
}
int main(){
  int n,m;
  while (scanf("%d%d",&n,&m)!=EOF){
    cout<<f(m,n)<<endl;
  }
  return 0;
}
