#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n;
  while(n--){
    cin>>s;
    int flag=1,i,j;
    for(i=1;i<=s.length();i++){
      if(s.length()%i==0){
        for(j=0;j<s.length();j++){
            if(s[j]==s[j%i])
              continue;
            else break;
          }
        if(j==s.length()){
          cout<<i<<endl;
          break;
        }
      }
    }
    if(n) cout<<endl;
  }
  return 0;
}
