#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int ans = 1;
        char c = s[0];
        for(int i=1,len=s.length();i<len;i++){
            if(c==s[i]){
              //cout<<s[i];
            }
            else {
              ans++;
            //  cout<<' '<<s[i];
            }
            c = s[i];
        }
        cout<<ans<<endl;
        c = s[0];
        cout<<s[0];
        for(int i=1,len=s.length();i<len;i++){
            if(c==s[i]){
              cout<<s[i];
            }
            else {
              cout<<' '<<s[i];
            }
            c = s[i];
        }
        cout<<endl;
    }
    return 0;
}
