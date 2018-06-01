#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<char,int > m;
int main(){
  for(int i=0;i<10;i++)
    m['0'+i]=i;
  int n;
  cin>>n;
  while(n--){
    string s;
    cin>>s;
    if(m[s[s.length()-1]]%2==0)
      cout<<"even"<<endl;
    else cout<<"odd"<<endl;
  }
  return 0;
}
