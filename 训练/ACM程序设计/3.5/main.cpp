/********************************
        斐波那契数
{f(0) = 0;f(1) = 1;f(n)=f(n-1)+f(n-2)
输入数据含有不多于50个的正整数n(0<=n<46)。
*********************************/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
    ifstream cin("in.txt");
    int a[47];
    a[0] = 0; a[1] = 1;
    for(int i=2;i <= 46; i++){
        a[i] = a[i-1] + a[i-2];
    }
    //查表(数组)
    int n;
    while(cin>>n){
        cout<<a[n]<<endl;
    }
    return 0;
}
