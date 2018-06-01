#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
map<string,string> mp;
string s,ss;
int main()
{
    cin >> s;
    while(cin>>s){
        if(s == "END")
            break;
        cin>>ss;
        mp[ss] = s;
    }
    //cout << mp["difh"] << endl;
    cin>>s;
    getline(cin,s);
    while(getline(cin,s)){
        ss = "";
        if(s == "END")
            break;
        ss = "";
        for(int i = 0; i < s.size(); i++){
            if(islower(s[i])){
                ss+=s[i];
            }else{
                if(mp.find(ss)!=mp.end()){
                    cout << mp[ss];
                }
                else cout << ss;
                ss = "";
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
