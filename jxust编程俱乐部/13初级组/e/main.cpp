#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        float h,a;
        cin>>h>>a;
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<h/tan(a)<<endl;;
    }
    return 0;
}
