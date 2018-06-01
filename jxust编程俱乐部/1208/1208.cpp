#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int y){
  return a>y;
}
int main(){
  int n,a[160];
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a,a+n,cmp);
  cout<<a[4]<<endl;
  return 0;
}
