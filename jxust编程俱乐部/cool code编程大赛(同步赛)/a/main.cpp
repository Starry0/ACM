#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long a[4];
    while(cin>>a[0]>>a[1]>>a[2]){
        sort(a,a+3);
        if((a[0]+a[1])*2 <= a[2]){
            cout << a[1] + a[0] <<endl;
        }
        else cout << (a[0]+a[1]+a[2])/3<<endl;
    }
    return 0;
}
