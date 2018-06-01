#include <bits/stdc++.h>
using namespace std;
int main(){
    string s[1000],ss[1000];
    for(int i=0;;i++){
        cin>>s[i];
        if(s[i][0]=='#')
            break;
    }
    int k;
    for(int i=0;;i++){
        cin>>ss[i];
        if(ss[i][0]=='_')
            k=i;
        else if(ss[i][0]=='#')
            break;
    }
    cout<<s[k]<<endl;
    return 0;
}
