#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    string s,ss;
    int ans=0,a,j,b;
    cin>>s;
    for(int q=0;q<s.length();q++){
        if(isalpha(s[q]))
            s[q]=tolower(s[q]);
    }
    getchar();
    while(getline(cin,ss)){
            for(int w=0;w<ss.length();w++){
                if(isalpha(ss[w]))
                    ss[w]=tolower(ss[w]);
            }
        if(ss=="end_of_text")
            break;
        a=s.length();b=ss.length();
        //cout<<a<<' '<<b<<endl;
        for(int i=0;i<b-a+1;i++){
            if(ss[i]==s[0]){
                //cout<<i<<endl;
                for(j=1;j<a;j++){
                    if(ss[i+j]!=s[j])
                        break;
                    //else cout<<i+j<<endl;
                }
                if(j==a)
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
