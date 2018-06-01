#include <iostream>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            if((i+1)==1)a[i]=1;
            else {
                for(int j=2;j<=(i+1);j++)
                if((i+1)%j==0){
                    a[i]=j;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
            k++;
        cout<<k<<endl;
    }
    return 0;
}
