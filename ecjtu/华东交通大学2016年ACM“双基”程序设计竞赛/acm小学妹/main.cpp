#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++)
        cin>>a[i][0]>>a[i][1];
   // sort(a,a+n);
    for(int i=0;i<=n;i++)
        cout<<a[i][0]<<' '<<a[i][1]<<endl;
    return 0;
}
