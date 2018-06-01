#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll f(int x){
  if(x==1)
    return 0;
  else if(x==2)
    return 1;
  else  return (x-1)*f(x-1)+f(x-2);
}
int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    cout<<f(n)<<endl;
  }
}
