#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,y,i;
        cin>>n;
        for(i=1;;i++){
            y=(pow(3,i)-1)/2;
            if(y>=n)break;
        }
        cout<<i<<endl;
    }
    return 0;
}
