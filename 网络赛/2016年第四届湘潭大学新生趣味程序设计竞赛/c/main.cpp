#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        double tt,mm;
        scanf("%lf:%lf",&tt,&mm);
        if(tt>=12)tt-=12;
        double ts,ms,sum=0;
        ms=mm*6.0;
        ts=tt*30.0+mm*0.5;
        sum=fabs(ts-ms);
        if(sum>180)
            sum=360-sum;
        if(sum==(int)sum)
            cout<<(int)sum<<endl;
        else {
            //cout.precision(2);
            cout<<sum<<endl;
        }
    }
    return 0;
}
