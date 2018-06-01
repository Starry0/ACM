#include <iostream>
#include <map>
#include <cstring>
using namespace std;
map<string,int> m;
int FIND(string ss,string s){
  int ans=0;
  int i,j=0;
  for(int i=0;i<ss.length();i++){
    if(ss[i]==s[0]){
      for(j=1;j<s.length();j++){
        if(ss[i+j]!=s[j]){
          break;
        }
      }
    }
    if(j==s.length())
    ans++;
  }
  return ans;
}
int main(){
  string s,ss;
  cin>>s;
  for(int i=0;i<s.length();i++){
    if(isalpha(s[i]))
        s[i]=tolower(s[i]);
  }
  while (cin>>ss) {
    for(int i=0;i<ss.length();i++){
      if(isalpha(ss[i]))
      ss[i]=tolower(ss[i]);
    }
    if(ss=="end_of_text")
        break;
    int ans=FIND(ss,s);
    m[s]+=ans;
  }
  cout<<m[s]<<endl;
  return 0;
}
