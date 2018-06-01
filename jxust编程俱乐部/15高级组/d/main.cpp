#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,xo,yo;
        float x=0.0,y=0.0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>xo>>yo;
            x+=xo;y+=yo;
        }
        x=(float)x/n;y=(float)y/n;
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}
