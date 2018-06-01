#include <iostream>
using namespace std;
int  main(){
  int  n;
  cin>>n;
  int  h=0;
  for(int  i=n;i>=1;i--){
    int  k=2;
    int  first=0.5*(n-i+1)*(n-i)+1;
    int  w=first;
    cout<<first;
    for(int  j=1;j<i;j++){
      w=w+k+h;
      cout<<' '<<w;
      k++;
    //  break;
    }
    cout<<endl;
    h++;
    //break;
  }
  return 0;
}
