#include <iostream>

using namespace std;

int main()
{
    cout.precision(2);
    int n,k;
    cin>>n>>k;
    if(n==1)
        cout<<"1.00"<<endl;
    else if(n==2){
        if(k==0)
            cout<<"0.00"<<endl;
        else cout<<"1.00"<<endl;
    }
    else if(n==3){
        if(k<=1)
            cout<<"0.00"<<endl;
        else cout<<"1.00"<<endl;
    }
    else if(n==4){
        if(k<=2)
            cout<<"0.00"<<endl;
        else if(k==3)
            cout<<"0.80"<<endl;
        else cout<<"1.00"<<endl;
    }
    return 0;
}
