#include<iostream>
#include<map>
using namespace std;
int main()
{
    int a,b,c=99;
    map<int,int> m;
    for(int i=1917;i<=2016;i++){
        a=i/100;
        b=i-a*100;
        m[a+b]=c--;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<m[n]<<endl;
    }
    return 0;
}
