#include <iostream>
using namespace std;

int main()
{
    int m;
    while(cin>>m){
        int s=0,b=0,n=m;
        while(m>0){
            s=m%10;
            b=b*10+s;
            m=m/10;
        }
        if(n==b)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
