#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    while(n--){
        cin>>m;
        m--;
        cout<<m/2+1<<endl;
    }
    return 0;
}
