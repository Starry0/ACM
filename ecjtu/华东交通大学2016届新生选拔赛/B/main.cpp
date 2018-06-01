#include <iostream>
#include <cmath>
#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    ll n,m=0,a,b;
    while(scanf("%lld",&n)!=EOF){
        int k=log10(n)+1;
        m=pow(2,k-1);
        /*if(log10(n-(n/pow(10,k-1))*pow(10,k-1))!=0){
            k=log10(n-(n/pow(10,k-1))*pow(10,k-1));
            m+=pow(2,k);
            }
        cout<<m<<endl;*/
        a=n/pow(10,k-1);
        b=n-a*pow(10,k-1);
        if(b!=0){
            k=log10(b);
            m=m+pow(2,k);
        }
        cout<<m<<endl;
    }
    return 0;
}
