#include <iostream>
using namespace std;

int main(){
  float x;
  while(cin>>x){
    if(x>100)
      cout<<"Score is error!"<<endl;
    else if(x>=90)
      cout<<"A"<<endl;
    else if(x>=80)
      cout<<"B"<<endl;
    else if(x>=70)
      cout<<"C"<<endl;
    else if(x>=60)
      cout<<"D"<<endl;
    else if(x>=0)
      cout<<"E"<<endl;
    else cout<<"Score is error!"<<endl;
  }
  return 0;
}
