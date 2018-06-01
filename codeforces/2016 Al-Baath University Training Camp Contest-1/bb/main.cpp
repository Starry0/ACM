#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string s,ss;
    while(t--){
        cin>>s>>ss;
        if(s.length()!=s.length())
            cout<<"No"<<endl;
        else {
            int n=s.length();
            for(int i=0;i<n;i++){
                s[i]=tolower(s[i]);
                ss[i]=tolower(ss[i]);
            }
            for(int i=0;i<n;i++){
                if(s[i]=='p')
                    s[i]='b';
                if(ss[i]=='p')
                    ss[i]='b';
                if(s[i]=='i')
                    s[i]='e';
                if(ss[i]=='i')
                    ss[i]='e';
            }
            if(s==ss)
                cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
