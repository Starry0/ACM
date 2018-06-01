#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n){
        int a[n],i=0,sn=0;
        while(n--){
            cin>>a[i];
            sn+=a[i];
            i++;
        }
        cout<<sn<<endl;
        cin>>n;
    }
    return 0;
}
