#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,c,d,e,f,g;
    while(scanf("%d/%d/%d",&a,&b,&c)!=EOF){
        if(b==1)
        d=c;
        else if(b==2)
        d=31+c;
        else if(b==3)
        d=31+28+c;
        else if(b==4)
        d=31+28+31+c;
        else if(b==5)
        d=31+31+28+30+c;
        else if(b==6)
        d=31+28+31+30+31+c;
        else if(b==7)
        d=31+28+31+30+31+30+c;
        else if(b==8)
        d=31+28+31+30+31+30+31+c;
        else if(b==9)
        d=31+28+31+30+31+30+31+31+c;
        else if(b==10)
        d=31+28+31+30+31+30+31+31+30+c;
        else if(b==11)
        d=31+28+31+30+31+30+31+31+30+31+c;
        else if(b==12)
        d=31+28+31+30+31+30+31+31+30+31+c+30;
          e=a%100;
        f=a%400;
        g=a%4;
        if(e==0)
        {
            if(f==0)
            d=1+d;
            else
            d=d;
        }
        else if(g=0)
        d=d+1;
        else
        d=d;
        printf("%d\n",d);

    }
    return 0;
}
