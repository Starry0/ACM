#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll f(ll x,ll y){
    ll r=x%y;
    ll a=x,b=y;
    while(r!=0){
        x=y;
        y=r;
        r=x%y;
    }
    return a*b/y;
}
int main()
{
    ll a,b,c,q;
    while(cin>>a>>b>>c){
            q=f(a,b);
            q=f(q,c);
            cout<<q<<endl;
            }
    return 0;
}
