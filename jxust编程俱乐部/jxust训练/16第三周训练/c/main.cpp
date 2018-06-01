#include <iostream>

using namespace std;

int main()
{
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        a=a%100;b=b%100;
        cout<<(a+b)%100<<endl;
    }
    return 0;
}
