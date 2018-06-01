/***********************************
将十进制整数换成二进制数。
************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int main(){
    ifstream cin("in.txt");
    int n;
    while(cin>>n){
        if(n==0){
          cout<<"          0-->0\n";
          continue;
        }
        s="";
      //  cout<<s<<endl;
        for(int a=n;a;a=a/2){
          //cout<<a<<endl;
          s=s+(a%2?"1":"0");
        //  cout<<s<<endl;
        }
        std::reverse(s.begin(),s.end());
        const char*sss=s.c_str();
        cout.width(11);
        cout<<n<<(n<0?"-->-":"-->")<<sss<<'\n';
    }
    return 0;
}
