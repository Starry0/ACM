#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double y,a,b,c;
    cin>>a>>b>>c;
    y=exp(b*log(a)+log(c));
    cout<<y<<endl;
    return 0;
}
