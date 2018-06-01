#include <bits/stdc++.h>
using namespace std;
map<char,int>m;
int main(){
    string s,ss,sss;
    cin>>s;
    for(int i=0; i<26;i++)
        m[s[i]] = i;
    while(cin>>ss){
        int maxn = 1,maxn1=1;
        //cout<<ss<<endl;
        for(int i=1,len=ss.length();i<len;i++){
            if(m[ss[i]]>=m[ss[i-1]])
                maxn1++;
            else {
                if(maxn1>maxn){
                    maxn = maxn1;
                    maxn1 = 1;
                }
            }
        }
        sss+='0'+max(maxn,maxn1);
    }
    cout<<sss<<endl;
}
