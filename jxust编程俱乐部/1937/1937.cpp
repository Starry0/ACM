/*****************************
题目意思理解错误了，5555555555555；
不过我这方法还是要记下的。。。。。
******************************/

#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
map<char ,int >m;
int main(){
  /*for(int i=0;i<10;i++)
    m['0'+i]=i;
  string s;
  while(getline(cin,s)){
    ll j=0,o=0;
    for(int i=0;i<s.length();i++){
      if(m.count(s[i])){
        if(m[s[i]]%2==0){
          o+=m[s[i]]*m[s[i]];
        }
        else j=m[s[i]]*m[s[i]]*m[s[i]];
      }
    }
    cout<<o<<' '<<j<<endl;
  }*/
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF){
    ll o=0,j=0;
    for(int i=n;i<=m;i++){
      if(i%2==0)
        o+=i*i;
      else j+=i*i*i;
    }
    cout<<o<<' '<<j<<endl;
  }
  return 0;
}
