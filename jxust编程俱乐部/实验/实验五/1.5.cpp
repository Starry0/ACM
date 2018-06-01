#include <stdio.h>
int main()
{
    int a=3,b=4,c=5,t;
    if (a<b&&a<c) t=a;a=b;b=t;
    if (a<b&&a<c) t=a;a=c;c=t;
    printf("a=%d,b=%d,c=%d\n",a,b,c);
    return 0;
}
