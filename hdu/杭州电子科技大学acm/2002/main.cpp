#include <iostream>
#include <cstdio>
#define PI 3.1415927

using namespace std;

int main()
{
    double r,v;
    while(cin>>r){
        v=4.0/3.0*PI*r*r*r;
        printf("%.3lf\n",v);
    }
    return 0;
}
