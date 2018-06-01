#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        double sum = 0;
        cout.precision(4);
        cin>>n;
        for(int i=1;i<=n;i++){
            sum+=1.0/i;
        }
        cout<<fixed<<sum<<endl;
    }
    return 0;
}
