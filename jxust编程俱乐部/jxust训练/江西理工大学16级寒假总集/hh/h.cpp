/*
在这编译不了，但在CB可以，以后要仔细观察，好坑的一题。。。。
*/
#include <iostream>
#include <cstring>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s[0]==s[s.length()-1]){
    if(s.length()%2==0)
      cout<<"First"<<endl;
    else cout<<"Second"<<endl;
  }
  else {
    if(s.length()%2==0)
      cout<<"Second"<<endl;
    else cout<<"First"<<endl;
  }
  return 0;
}
