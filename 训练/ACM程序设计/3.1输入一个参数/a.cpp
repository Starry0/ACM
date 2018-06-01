#include <iostream>
#include <fstream>
using namespace std;
int main(){
  ifstream cin("in.txt");
  int n;
  while(cin>>n){
    cout<<n*n<<endl;
  }
  return 0;
}
