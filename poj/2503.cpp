#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;
map<string,string>:: iterator it;
int main(){
    string s,ss,sss;
    char s1[30],s2[30];
    while(cin>>s){
        if(s=="")break;
        cin>>ss;
        mp[ss] = s;
    }
    for(it = mp.begin();it!=mp.end();++it){
        cout <<(*it).first<< "+" << (*it).second<< "++" << endl;
    }
    cout << mp["oopslay"] << endl;
    while(scanf("%s",s1)){
        // cout << mp[s] << endl;
        s = "";
        s = s1;
        if(mp.count(s))cout << "eh"<<endl;
        else cout << mp[s] << endl;
    }
    return 0;
}
