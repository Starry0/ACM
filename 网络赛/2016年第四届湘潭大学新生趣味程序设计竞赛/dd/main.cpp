#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;
    string ss,x1,s;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>x1;
        int m=x1.length();
        for(int i=0;i<n-m;i++){
            if(i==0){
                for(int j=1;j<10;j++){
                    s="0";
                    s[0]+=j;
                    //cout<<s<<endl;
                    if(x1.find(s)==string::npos){
                        ss=s;
                       // cout<<s<<endl;
                        break;
                    }
                }
            }
            else {
                for(int j=0;j<10;j++){
                    s="0";
                    s[0]+=j;
                    if(ss.find(s)==string::npos&&x1.find(s)==string::npos){
                        ss=ss+s;
                        break;
                    }
                }
            }
        }
        cout<<ss<<x1<<endl;
    }

    return 0;
}
