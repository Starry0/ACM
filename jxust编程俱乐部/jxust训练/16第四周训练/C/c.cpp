#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int main(){
  int a,b,c;
  while(scanf("%d%c%d",&a,&c,&b)!=EOF){
    if(c=='-')
    cout<<a-b<<endl;
    else if(c=='+')
    cout<<a+b<<endl;
    else if(c=='*')
    cout<<a*b<<endl;
    else if(c=='/')
    cout<<a/b<<endl;
  }
  return 0;
}
