#include <iostream>
using namespace std;

int f(int x){
  return x==0?3:(f(x-1)-1)*2;
}
int main(){
  int n,a;
  cin>>n;
  while(n--){
    cin>>a;
    cout<<f(a)<<endl;
  }
  return 0;
}
