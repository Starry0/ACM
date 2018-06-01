#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    char c;
    int ans = 0;
    cin>>s>>c;
    for(int i=0,len=s.length();i<len;i++){
        if(s[i]==c)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
