#include <iostream>

using namespace std;
void insefirsr(int *p,int k){
    int temp,i=k-1;
    temp=*(p+k);
    while(i--){
        *(p+i+2)=*(p+i+1);
    }
    *(p+1)=temp;
}
int main()
{
    int n,q;
    cin>>n>>q;
    while(n!=0&&q!=0)
    {
        int a[n+1];
        for(int i=1;i<=n;i++)
            a[i]=i;
        while(q--){
            int k;
            cin>>k;
            insefirsr(a,k);
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
        cin>>n>>q;
    }
    return 0;
}
