#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        int i=0,j=0,k=0,d;
        string str[n];
        while(n--){
            cin>>str[i]>>m;
            if(m>40){
                if(m%40==0)
                d=m/40;
                else d=m/40+1;
            }
            else d=1;
            j+=d;
            if(d>1)k+=3;
        }
        cout<<j<<' '<<k<<endl;
    }
    return 0;
}
