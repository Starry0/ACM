#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0X3f3f3f3f;
int main(){
  int n,c,d,l=-INF,r=INF;
  cin>>n;
  while(n--){
    cin>>c>>d;
    if(d==1&&l<1900)
      l=1900;
    if(d==2&&r>1899)
      r=1899;
    l+=c;
    r+=c;
  }
  if(l>r)
    cout<<"Impossible"<<endl;
  else if(max(l,r)>20001899)
    cout<<"Infinity"<<endl;
  else cout<<r<<endl;
  return 0;
}
