#include <iostream>
using namespace std;
int main(){
  int n,m,t;
  cin>>t;
  while(t--){
    cin>>n>>m;
    n%=100;m%=100;
    cout<<(n+m)%100<<endl;
  }
  return 0;
}
