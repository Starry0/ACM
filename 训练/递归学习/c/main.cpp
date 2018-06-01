#include <iostream>
#include <cstdio>
using namespace std;
double f(double x,int n){
    if(n == 0)return 1;
    else if(n == 1)return x;
    else if(n > 1) return ((2.0*n-1)*x*f(x,n-1)-(n-1)*f(x,n-2))/n;
}
int main(){
    int n;
    cin >> n;
    for(double i = -1; i <= 1.0001; i+=0.02){
        printf("%.4f\n",f(i, n));
    }
    return 0;
}
