/************************************
判断一个数是否为对称且不大于五位数的素数
***********************************/
#include <fstream>
#include <iostream>
using namespace std;

bool isPreme(int n){
    if(n==1)return false;
    if(n!=2&&n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0)
            return false;
    return true;
}
bool issym(int n){
    int a=n,b=0;
    while(a>0){
        b=b*10+a%10;
        a/=10;
    }
    if(n==b)
        return true;
    else return false;
}
int main(){
    ifstream cin("in.txt");
    int n;
    while(cin>>n){
        cout<<(n<100000&&issym(n)&&isPreme(n)?"Yes\n":"No\n");
    }
    return 0;
}
