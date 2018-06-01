#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char a[110];
  int n;
  cin>>n>>a;
  int x=0,maxn=0;
  for(int i=0;i<n;i++){
    if(a[i]=='I')
      x++;
    else x--;
    if(x>maxn)
      maxn=x;
  }
  cout<<maxn<<endl;
  return 0;
}
