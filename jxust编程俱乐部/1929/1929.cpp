#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int a,maxn=-0x0FFFFFFF;
  while(scanf("%d",&a)!=EOF){
    if(a==0){
      cout<<maxn<<endl;
      maxn=-0x0FFFFFFF;
      continue;
    }
    if(a>maxn)
      maxn=a;
  }
  return 0;
}
