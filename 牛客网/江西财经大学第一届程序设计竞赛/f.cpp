#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
#define ll long long
const int N = 11;
double f(double x) {
    return 2018*x*x*x*x+21*x+5*x*x*x+5*x*x+14;
}
int main() {
    int t;
    // printf("%.8lf\n",f(100));
    double MAX = 201805052114;
    cin >> t;
    while (t--) {
        double y;
        cin >> y;
        if(y < 14 || y > 201805052114) {
            printf("-1\n");
            continue;
        }
        double MIN = 1000000;
        double x;
        for(double i = 0; i <= 100; i += 0.0001) {
            if(fabs(f(i)-y) < MIN) {
                MIN = fabs(f(i)-y);
                x = i;
            }
        }
        printf("%.4lf\n",x);
    }
    return 0;
}
