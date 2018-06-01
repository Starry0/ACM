#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k,sn=1;
    string s;
    cin>>n>>k;
    for(int i = 1;i <= n; i++){
        sn *= i;
        while(sn%10 == 0)
            sn /= 10;
    }
    //cout<<sn<<endl;
    while(sn > 0){
        s += '0' +sn%10;
        sn/=10;
    }
    reverse(s.begin(),s.end());
    if(k>=s.length())
        cout<<s<<endl;
    else{
        int len = s.length();
        for(int i=len-k;i<len;i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
