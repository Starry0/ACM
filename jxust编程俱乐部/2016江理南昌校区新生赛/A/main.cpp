#include <iostream>

using namespace std;

int main()
{
    int a,c,b;
    cin>>a>>b>>c;
    int z;
    if(a>b){
        if(b>c)z=b;
        else if(a>c)z=c;
        else z=a;
    }
    else {
        if(a>c)z=a;
        else if(b>c)z=c;
        else z=b;
    }
    cout<<z<<endl;
    return 0;
}
