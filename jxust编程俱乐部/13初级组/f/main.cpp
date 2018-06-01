#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if((x1-x3)*(x2-x3)<=0){
            if(x3==x1){cout<<"no"<<endl;break;}
            if((y3-y1)*(x3-x2)==(y3-y2)*(x3-x1))
                cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;
}
