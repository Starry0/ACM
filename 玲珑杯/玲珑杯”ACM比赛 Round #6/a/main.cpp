#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    string s,ss;
    char aaa[13];
    ll t,a,b,p;
    cin>>t;
    while(t--){
        ll sum=0;
        cin>>a>>b>>p;
        ss='0'+p;
        if(b<p){
            cout<<sum<<endl;
            continue;
        }
        else {
            for(int i=a;i<=b;i++){
                sprintf(aaa,"%d",i);
                s=aaa;
               // cout<<s<<' '<<ss<<endl;
                if(s.find(ss)!=string::npos)sum++;
                s="";
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
