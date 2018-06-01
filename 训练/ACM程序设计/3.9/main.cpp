/***********************************
判断一个数是否为对称三位素数。所谓“对称”是指一个数，
倒过来还是该数。例如，375不是对称素数，因为倒过来变成了573.
************************************/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool isPreme(int n){
    int sqr = sqrt(n*1.0);
    for(int i = 2;i <= sqr; i++)
        if(n%i == 0) return false;
    return true;
}
int main(){
    ifstream cin("in.txt");
    int n;
    while(cin>>n){
        cout<<(n>100&&n<1000&&n/100==n%10&&isPreme(n)?"Yes\n":"No\n");

    }
    return 0;
}
