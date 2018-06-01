#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,ac,k,ans=0,a,sn=-1;
    cin>>n>>k;
    a=sqrt(n);
    for(int i=1;i<=a;i++){
        if(n%i==0)
            ans++;
        if(ans==k){
            sn=i;
            break;
        }
    }
    if(sn==-1){
        if(a*a==n) ac = 2*ans - 1;
        else ac = 2*ans;
        if(k<=ac&&k>ans){
            if(a*a==n)ans--;
            for(int i=a;i>=1;i--){
                if(n%i==0)
                    ans++;
                if(ans==k){
                    sn=n/i;
                    break;
                }
            }
        }
    }
    cout<<sn<<endl;
    return 0;
}
