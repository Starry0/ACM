#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        ll sum=0;
        cin>>a;sum=a;
        for(int i=1;i<n;i++){
            cin>>b;
            a=__gcd(a,b);
            sum+=b;
        }
        cout<<a<<' '<<sum/a<<endl;
    }
    return 0;
}
