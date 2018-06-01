#include <iostream>

using namespace std;

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int sum=0,a;
        for(int i=0;i<n;i++){
            cin>>a;
            sum+=a;
        }
        if((sum+1500)==m)
            cout<<"Correct"<<endl;
        else cout<<"Bug"<<endl;
        }
    return 0;
}
