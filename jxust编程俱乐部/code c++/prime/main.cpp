#include <iostream>
using namespace std;
int main()
{
    for(int i=100;i<1000;i++)
    {
        int h,t,d;
        h=i/100;
        t=(i-h*100)/10;
        d=i%10;
        if(i==(h*h*h+t*t*t+d*d*d))cout<<i<<endl;
    }
    return 0;
}
