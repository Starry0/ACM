#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
  string s,ss;
  int ans=0;
  cin>>s;
  for(int i=0;i<s.length();i++){
    if(isalpha(s[i]))
    s[i]=tolower(s[i]);
  }
  while (getline(cin,ss)) {
      for(int i=0;i<ss.length();i++){
        if(isalpha(ss[i]))
        ss[i]=tolower(ss[i]);
      }
      if(ss=="end_of_text")
      break;
    while (ss.find(s)!=string::npos) {
      ans++;
      int k=ss.find(s)+s.length();
    //  cout<<k<<endl;
      ss=ss.substr(k,ss.size()-k);
    }
  }
  cout<<ans<<endl;
}
