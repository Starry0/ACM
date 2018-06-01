#include <bits/stdc++.h>
#define ll long long
using namespace std;
double p,q,r,s,t,u;
double fun(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*(x)*(x)+u;
}
int main(){
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF){
        if(fun(0) < 0 || fun(1) > 0){
            printf("No solution\n");
            continue;
        }
        int flag = 0;
        double i = 0, j = 1, mid;
        while(1){
            mid = (i+j)/2.0;
            if(fabs(fun(mid)) < 1e-9){
                printf("%.4lf\n",mid);
                flag = 1;
                break;
            }
            if(fun(mid) > 0) i = mid;
            else if(fun(mid) < 0) j = mid;
        }
        if(!flag)printf("No solution\n");
    }
    return 0;
}
