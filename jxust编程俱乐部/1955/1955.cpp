#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  cout<<n/__gcd(n,m)*m<<endl;
  return 0;
}
