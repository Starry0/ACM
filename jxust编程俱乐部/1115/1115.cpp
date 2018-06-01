#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int ans = 0;
    while(cin>>s){
        int a=0,b=0,c=0;
        int i,len = s.length(),flag=1,k1=0,k2=0;
        for(i = 0;i < len; i++){
            if(s[i]=='-'){
              k1 = 1;break;
            }
            if(s[i]=='+'){
              k2=1;break;
            }
            a = a*10 + s[i] - '0';
        }
        for( ++i;i < len; i++){
            if(s[i]=='=')
                break;
            b = b*10 + s[i] - '0';
        }
        for( ++i;i < len; i++){
            if(s[i]=='?'){
              flag = 0;break;
            }
            c = c*10 + s[i] -'0';
        }
        //cout<<a<<' '<<b<<' '<<c<<' '<<k1<<' '<<k2<<endl;
        if(flag){
            if(k1&&(a-b)==c)
                ans++;
            else if(k2&&(a+b)==c)
                ans++;
        }
        else continue;
    }
    cout<<ans<<endl;
    return 0;
}
