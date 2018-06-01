#include <stdio.h>
int main()
{
    int a=0,b=1,c=0,d=20;
    if (a)
        d-=10;
    else if(b)
        if(!c)
            d=15;
        else
            d=25;
    printf("d=%d\n",d);
    return 0;
}
