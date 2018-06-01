#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
  int n,p=20000;
  char s[10];
  cin>>n;
  while(scanf("%d%s",&n,s)!=EOF){
    if(p==20000){
      if(s[0]!='S'){
        cout<<"NO"<<endl;
        return 0;
      }
    }
    if(p==0){
      if(s[0]!='N'){
        cout<<"NO"<<endl;
        return 0;
      }
    }
    if(s[0]=='S'||s[0]=='N'){
      if(n>20000){
        cout<<"NO"<<endl;
        return 0;
      }
    }
    if(s[0]=='S'){
      if(p-n<0){
        cout<<"NO"<<endl;
        return 0;
      }
      else p-=n;
    }
    if(s[0]=='N'){
      if(p+n>20000){
        cout<<"NO"<<endl;
        return 0;
      }
      else p+=n;
    }
  }
  if(p==20000)
    cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
