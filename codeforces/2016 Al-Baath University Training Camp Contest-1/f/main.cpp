#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;
    string a,b,c[4];
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a.find(b)!=string::npos)
            cout<<"good"<<endl;
        else {
            c[0]=b[0];c[0]+=b[1];c[0]+=b[2];
            c[1]=b[0];c[1]+=b[1];c[1]+=b[3];
            c[2]=b[0];c[2]+=b[2];c[2]+=b[3];
            c[3]=b[1];c[3]+=b[2];c[3]+=b[3];
           // cout<<c[0]<<endl<<c[1]<<endl<<c[2]<<endl<<c[3]<<endl;
            if(a.find(c[0])!=string::npos||a.find(c[1])!=string::npos||a.find(c[2])!=string::npos||a.find(c[3])!=string::npos)
                cout<<"almost good"<<endl;
            else cout<<"none"<<endl;
        }

    }
    return 0;
}
