#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n;
  cin>>n;
  while(n--){
    int sum=0,a=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
      if(s[i]=='O'){
        a++;
      }
      else a=0;
      sum+=a;
    }
    cout<<sum<<endl;
  }
  return 0;
}
