#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    for(int i=0,len=s.length();i<len;i++)
        if(isalpha(s[i]))
            s[i]=tolower(s[i]);
    cout<<s<<endl;
    for(int i=0,len=s.length();i<len;i++)
        if(isalpha(s[i]))
            s[i]=s[i] - 32;
    cout<<s<<endl;
    return 0;
}
