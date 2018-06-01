#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
int main(){
    string s;
    while(cin>>s){
        for(int i=0,len=s.length();i<len;i++){
            s[i]=tolower(s[i]);
        }
        m[s]++;
    }
    cout<<m.size()<<endl;
    return 0;
}
