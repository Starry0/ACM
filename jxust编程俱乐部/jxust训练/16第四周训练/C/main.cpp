#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    ll a,s,b;
    while(cin>>a>>b>>s){
            a=abs(a);b=abs(b);
            if(a<=(s-b)&&(s-a-b)%2==0)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
    }
    return 0;
}
