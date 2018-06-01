#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
map<char ,int> m;
int main(){
  char s;
  int o=0,j=0;
  while ((s=getchar())!='\n'){
    m[s]++;
    if(m[s]==2){
      o++;
      m[s]=0;
    }
  }
  for(int i=0;i<26;i++){
    /*if(m['a'+i]%2==0&&m['a'+i]!=0)
      o++;*/
    if(m['a'+i]%2!=0&&m['a'+i]!=0)j++;
  }
  if(o%2==0&&j%2!=0||o%2!=0&&j%2==0)
    cout<<"First"<<endl;
  else if(o%2==0&&j%2==0||o%2!=0&&j%2!=0)
    cout<<"Second"<<endl;
  return 0;
}
