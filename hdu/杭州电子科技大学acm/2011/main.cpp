#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,k;
    cin>>n;
    cout.precision(2);
    while(n--){
        double sn=0.0;
        cin>>k;
        for(int i=1;i<=k;i++){
            sn+=1.0/i*pow(-1,i+1);
        }
        cout<<fixed<<sn<<endl;
    }
    return 0;
}
