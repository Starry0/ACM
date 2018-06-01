#include <iostream>
#define ll long long
using namespace std;
int main(){
  int n;
  ll at,am,as,bt,bm,bs,t,m,s;
  cin>>n;
  while(n--){
    cin>>at>>am>>as>>bt>>bm>>bs;
    int flag=0,flag1=0;
    if(as+bs>=60){
      flag=1;
    }
    s=(as+bs)%60;
    if(am+bm+flag>=60){
      flag1=1;
    }
    m=(am+bm+flag)%60;
    t=at+bt+flag1;
    cout<<t<<' '<<m<<' '<<s<<endl;
  }
  return 0;
}
