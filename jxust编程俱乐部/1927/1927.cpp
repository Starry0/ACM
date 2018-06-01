#include <iostream>
#include <cstring>
using namespace std;
int main(){
  string s;
  cin>>s;
  int i=0,j=s.length()-1;
  while(i<=j){
    if(s[i]==s[j]){
      i++;j--;
    }
    else break;
  }
  if(i>j)
    cout<<"Y"<<endl;
  else cout<<"N"<<endl;
  return 0;
}
