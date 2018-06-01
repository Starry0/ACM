#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double a, b, c, d, l, r;
double f(double x){
    return fabs(a*x*x*x + b*x*x + c*x + d);
}
int main()
{
    while(cin>>a>>b>>c>>d>>l>>r){
        double re = l;
        double ans = f(l);
        while(r - re >= 0.01){
            ans = max(ans, f(re));
            re += 0.01;
        }
        ans = max(ans, f(r));
        printf("%.2lf\n",ans);
    }
    return 0;
}
