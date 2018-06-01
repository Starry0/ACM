#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double n;
    int m;
    while(scanf("%lf%d",&n,&m)!=EOF){
        double sum=n;
        for(int i=0;i<m-1;i++){
            n=sqrt(n);
            sum+=n;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
