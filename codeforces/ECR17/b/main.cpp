#include <bits/stdc++.h>
#define ll long long
const int maxn = 3e5+1;
using namespace std;
ll usb[maxn],ps[maxn];

int main()
{
    ll i,j,a,b,c,m,k,su=0,p=0,sum=0;
    string ss;
    cin>>a>>b>>c>>m;
    for(i=1;i<=m;i++){
        cin>>k>>ss;
        if(ss=="USB"){
            usb[su++]=k;
        }
        else if(ss=="PS/2"){
            ps[p++]=k;
        }
    }
    k=0;
    sort(usb,usb+su);sort(ps,ps+p);
    for(i=0;i<min(a,su);i++){
        k++;
        sum+=usb[i];
        usb[i]=0;
    }
    for(j=0;j<min(b,p);j++){
        k++;
        sum+=ps[j];
        ps[j]=0;
    }
    for(int q=0;q<c;q++){
        if()
    }
    if(a<su){
        k+=a;
        for(i=0;i<a;i++){
            sum+=usb[i];
        }
        if(b<=p){
            k+=b;
            for(j=0;j<b;j++)
                sum+=ps[j];
            for(int q=0;q<c;q++){
                if(j>=b&&i>=a)
                    break;
                else if(j>=b&&i<a){
                    sum+=usb[i++];
                    k++;
                }
                else if(j<b&&i>=a){
                    sum+=ps[j++];
                    k++;
                }
                else if(j<b&&i<a){
                    if(usb[i]>ps[j]){
                        sum+=ps[j++];
                        k++;
                    }
                    else {
                        sum+=usb[i++];
                        k++;
                    }
                }
            }
        }
        else {
            k+=p;
            for(j=0;j<p;j++)
                sum+=ps[j];
            for(int q=0;q<c;q++){
                if(i>=su)
                    break;
                else {
                    k++;
                    sum+=usb[i++];
                }
            }
        }
    }
    else {
        k+=su;
        for(i=0;i<su;i++)
            sum+=usb[i];
        if(b<=p){
            k+=b;
            for(j=0;j<b;j++){
                sum+=ps[j];
            }
            for(int q=0;q<c;q++){
                if(j>=p)
                    break;
                else {
                    k++;
                    sum+=ps[j++];
                }
            }
        }
        else{
            k+=p;
            for(j=0;j<p;j++)
                sum+=ps[j];
        }
    }
    cout<<k<<' '<<sum<<endl;
    return 0;
}
