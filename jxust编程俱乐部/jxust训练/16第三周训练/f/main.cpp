#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
//char a[110];
int main()
{
    string s,ss="";
    int a=0,b=0,c=0,d=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='h'){
            if(a==0){
                ss+=s[i];
                a++;
            }
        }
        if(s[i]=='e'){
            if(b==0){
                ss+=s[i];
                b++;
            }
        }
        if(s[i]=='l'){
            if(c<2){
                ss+=s[i];
                c++;
            }
        }
        if(s[i]=='o'){
            if(d==0){
                ss+=s[i];
                d++;
            }
        }
    }
    if(ss=="hello")
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
