#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int a[2],b[2],c[2],d[2],m=0;
    cin>>a[0]>>a[1]>>b[0]>>b[1];
    cin>>c[0]>>c[1]>>d[0]>>d[1];
    if((a[1]-b[1])*(c[0]-d[0])==(c[1]-d[1])*(a[0]-b[0]))
        m=1;
    if((a[1]-c[1])*(b[0]-d[0])==(b[1]-d[1])*(a[0]-c[0]))
        m=1;
    if((a[1]-d[1])*(b[0]-c[0])==(b[1]-c[1])*(a[0]-d[0]))
        m=1;
    if(m)
        cout<<"%mengshen"<<endl;
    else cout<<"%X73"<<endl;
    return 0;
}
