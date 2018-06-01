#include <iostream>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,k=0;
        cin>>n;
        long long a[n][n];
        for(long long i=0;i<n;i++)
            for(long long j=0;j<n;j++)
            cin>>a[i][j];
        for(long long j=0;j<n;j++){
            long long MAX=a[0][j],m=1,z;
            for(z=0;z<n;z++)
                if(MAX>a[0][z])m=0;
            if(m){
                int l=1;
                for(long long i=0;i<n;i++)
                    if(MAX<a[i][j])l=0;
                    if(l)k++;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
