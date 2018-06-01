/***********************************
求两个正整数的最大公约数。
输入数据含有不多余50对的数据，每对数据由两个整数(0<n1,n2<2^32)。
************************************/
#include <iostream>
#include <fstream>
using namespace std;
int gcd(int x,int y){
    while(x!=y){
      if(x>y) x-=y;
      else y-=x;
    }
    return x;
}
int main(){
    ifstream cin("in.txt");
    int x,y;
    while(cin>>x>>y){
      cout<<gcd(x,y)*y<<endl;
    }
    return 0;
}
