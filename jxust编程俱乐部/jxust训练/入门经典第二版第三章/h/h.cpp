#include <bits/stdc++.h>
using namespace std;
int a[11];
int main(){
  int n,s;
  cin>>n;
  while(n--){
    memset(a,0,sizeof(a));
    cin>>s;
    for(int i=1;i<=s;i++){
      int x=i;
      while(x > 0){
        a[x%10]++;
        x/=10;
      }
    }
    for(int i=0;i<10;i++){
      if(i!=0)
        cout<<' ';
      cout<<a[i];
    }
    cout<<endl;
  }
  return 0;
}
