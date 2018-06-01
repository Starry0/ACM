#include <bits/stdc++.h>
using namespace std;
int a[102];
map<int,int>m;
int main(){
    for(int i=2;i<100;i++){
        int flag=1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0)
                flag=0;
        }
        if(flag)
            m[i]==1;
    }
    int t,n;
    cin>>t;
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m.count(abs(a[i]-a[j]))){
                    cout<<"YES"<<endl;
                    goto tt;
                }
            }
        }
        cout<<"NO"<<endl;
        tt:memset(a,0,sizeof(a));
    }
}
