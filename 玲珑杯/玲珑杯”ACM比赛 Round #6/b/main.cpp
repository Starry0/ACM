#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
ll a1[20],b1[20];
ll a[15];
ll f(ll x,ll p){
    int n=log10(x)+1,sum=0,q,w;
    if(n>1){
        q=pow(10,n-1);
        w=x/q;
        if(w>p)
            sum=q+a[n-2]*(w-1);
        else if(w==p)
            sum=a[n-2]*w+1;
        else
            sum=a[n-2]*w;
        return sum;
    }
    else if(n==1){
        if(x>=p)
            sum++;
        return sum;
    }
}
int main()
{
    a[0]=1;
    int n=10;
    for(int i=1;i<10;i++){
        a[i]=a[i-1]*9+n;
        n*=10;
    }
    //cout<<f(a,1000,1)<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<endl;
    int t;
    cin>>t;
    while(t--){
        ll a,b,p,suma=0,sumb=0,i=1;
        cin>>a>>b>>p;
        memset(a1,0,sizeof(a1));
        memset(b1,0,sizeof(b1));
        ll shi=1;
        while(a>0){
            ll fff=a%10;
            a1[i++]=fff*shi;
            a/=10;
            shi*=10;
           // cout<<a1[i-1]<<endl;
        }
        for(int j=1;a1[j];j++){
          //  cout<<a1[j]<<endl;
          suma=suma+f(a1[j],p);
           // cout<<f(a1[j],p)<<endl;;
        }
        cout<<suma<<endl;
       // cout<<suma<<endl;
       /* shi=1,i=1;
        while(b>0){
            ll fff=b%10;
            b1[i++]=fff*shi;
            fff/=10;
            shi*=10;
        }*/
    }
    return 0;
}
