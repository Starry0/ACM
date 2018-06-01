#include <iostream>

using namespace std;

int main()
{
    string s,ss,s1,ss1;
    int n;
    cin>>s>>ss>>n;
    cout<<s<<' '<<ss<<endl;
    for(int i = 0; i < n; i++){
        cin>>s1>>ss1;
        if ( s1 == s){
            s = ss1;
            cout<<s<<' '<<ss<<endl;
        }
        else {
            ss = ss1;
            cout<<s<<' '<<ss<<endl;
        }
    }
    return 0;
}
