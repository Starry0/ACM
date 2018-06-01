#include <iostream>

using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    string s,ss,sss;
    cin>>s;
    while(n--){
        cin>>ss;
        sss+=ss[0];
        sss+=ss[1];
        sss+=ss[2];
        //cout<<sss<<endl;
        if(sss==s)
            ans++;
        sss="";
        sss+=ss[5];
        sss+=ss[6];
        sss+=ss[7];
       // cout<<sss<<endl;
        if(sss==s)
            ans--;
        sss="";
    }
    if(ans==0)
        cout<<"home"<<endl;
    else cout<<"contest"<<endl;
    return 0;
}
