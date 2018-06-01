#include <iostream>
using namespace std;
int main()
{
    int a,b,c,z;
    while(cin>>a>>b>>c){
        if(a>b){
            if(b<c)z=b;
            else z=c;
        }
        else {
            if(c<a)z=c;
            else z=a;
        }
        cout<<z<<endl;
    }
    return 0;
}
