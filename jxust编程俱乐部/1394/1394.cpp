#include <bits/stdc++.h>
using namespace std;
struct DATE{
    string s;
    int a,b;
}date[110];
bool cmp(DATE a,DATE b){
    if(a.s!=b.s) return a.s>b.s;
    else if(a.a!=b.a) return a.a>b.a;
    else return a.b>b.b;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
           cin>>date[i].s>>date[i].a>>date[i].b;
        }
        sort(date,date+n,cmp);
        for(int i=0;i<n;i++){
            cout<<date[i].s<<' '<<date[i].a<<' '<<date[i].b<<endl;
        }
    }
    return 0;
}
