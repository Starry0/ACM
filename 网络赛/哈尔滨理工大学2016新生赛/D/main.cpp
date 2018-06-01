#include <iostream>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n,k=1,s=0;
        cin>>n;
        long long a[n+10];
        for(long long i=1;i<=n;i++){
            if(n%i==0)a[k++]=i;
        }

        long long y[k+1];
        for(long long i=1;i<k;i++){
                long long m=0;
            for(long long j=1;j<=a[i];j++){
                if(a[i]%j==0)m++;
            }
        y[i]=m;
        }
        for(long long i=1;i<k;i++)
            s=s+y[i]*y[i]*y[i];
        cout<<s<<endl;
    }
    return 0;
}
