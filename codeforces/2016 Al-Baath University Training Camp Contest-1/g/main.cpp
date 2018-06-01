#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll h,w,d,ok=0;
        cin>>h>>w>>d;
        h%=2*(w-1);
        int a=d;
        int b=2*w-d;
        if(h==a||h==b)
            ok=1;
        if(w==2){
            h%=w;
            if(!h && d%2==0||h&&d%2==1)
                ok=1;
        }
        if(ok)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
