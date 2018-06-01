#include <stdio.h>
int main()
{
    int n=1,m=0,c=2;
    if(n) c-=2;
    if (!m) c-=1;
    if (c) c+=1;
    printf("c=%d\n",c);
    return 0;
}
