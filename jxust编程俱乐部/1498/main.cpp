#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    ll i,j;
    while(scanf("%lld%lld",&i,&j)!=EOF){
        ll ans=0;
        while(i!=j){
            if(j%2==0){
                j/=2;
                ans++;
            }
            else {
                j=3*j+1;
                ans++;
            }
        }
        cout<<
    }
    return 0;
}
