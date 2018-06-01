#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14,g=9.8;
int main()
{
    double o,u,m,f,t,G;
    cout.precision(3);
    //cout<<sin(pi*90.0/180.0)<<endl;
    cin>>o>>u>>m;
    o=pi*o/180.0;
    cout<<fixed<<-(3*u*cos(o)*m*g-sin(o)*m*g)<<endl;
    return 0;
}
