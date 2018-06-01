#include <iostream>
#define ll long long
using namespace std;

int main(){
  int n;
  ll sn=0,s=1;
  cin>>n;
  for(int i=1;i<=n;i++){
    s*=i;
    sn+=s;
  }
  cout<<s<<endl;
  return 0;
}
