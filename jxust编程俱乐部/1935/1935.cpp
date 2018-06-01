#include <iostream>
#include <cstring>
using namespace std;
int main(){
  string s;
  int i,p,half,left,Right,maxn,mm;
  while(cin>>s){
    i=s.length();
    maxn=0;
    for(p=0;p<i-1;p++){
      mm=0;
      half=((i-1)-p)/2;
      //如果子串是奇数个字符
      if(((i-1)-p)%2==0){
        left=p+half-1;
        Right=p+half+1;
        mm=1;
      }
      else{
        left=p+half;
        Right=p+half+1;
      }
      while(left>=p){
        if(s[left]==s[Right]){
          mm+=2;
          left--;
          Right++;
        }
        else {
          break;
        }
      }
      if(mm>maxn)
        maxn=mm;
    }
    for(p=i-2;p>=1;p--){
      mm=0;
      half=p/2;
      if(p%2==0){
        left=half-1;
        Right=half+1;
        mm=1;
      }
      else {
        left=half;
        Right=half+1;
      }
      while(left>=0){
        if(s[left]==s[Right]){
          mm+=2;
          left--;
          Right++;
        }
        else break;
      }
      if(mm>maxn)
        maxn=mm;
    }
    cout<<maxn<<endl;
  }
  return 0;
}
