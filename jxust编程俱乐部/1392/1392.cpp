#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    double a,b;
    while(t--){
        cin>>a>>b;
        int c = int(a+b);
        if((a+b)-c<1e-6)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
