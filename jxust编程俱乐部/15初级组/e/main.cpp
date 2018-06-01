#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k=0;
        cin>>n>>m;
        int a[10000],b[10000],c[10000];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(a[i]==b[j])c[k++]=a[i];
        }
        if(k)cout<<c[0]<<' ';
        for(int i=1;i<k;i++){
            if(c[i]!=c[i-1])cout<<c[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
