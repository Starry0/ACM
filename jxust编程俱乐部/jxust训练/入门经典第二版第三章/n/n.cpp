#include <bits/stdc++.h>
using namespace std;
int main(){
  string t,s;
  while(cin>>s>>t){
    int j=0,flag=0;
    for(int i=0;i<t.length();i++){
      if(s[j]==t[i])
        j++;
      if(j==s.length()){
        flag=1;
        break;
      }
    }
    if(flag)
      printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
