#include<stdio.h>
int main()
{
    int x=1,y,z;
    x*=3+2;
    printf("%d\t",x);
    x*=y=z=5;
    printf("%d\t",x);
    x=y==z;
    printf("%d\n",x);
    x<<=2 ;
    printf("%d\n",x);
    x>>=2 ;
    printf("%d\n",x);
    x&=2;
    printf("x=%d\n",x);
    x^=2;
    printf("x=%d\n",x);
    return 0 ;
}
