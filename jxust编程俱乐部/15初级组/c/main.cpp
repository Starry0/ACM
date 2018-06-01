#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        string s,ss,sss;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            cin>>ss;
            int ans=ss.find(".");
            cout<<ans;
        }
    }
    return 0;
}
