#include <iostream>
using namespace std;
int x[105],y[1005];
int main() {
  int n,ans=0;
  cin>>n;
  for(int i=0;i<=n;i++){
    cin>>x[i]>>y[i];
  }
  cout<<(n-4)/2<<endl;
  return 0;
}
