#include <stdio.h>
int main()
{
    int sub(int n);
    int i=5;
    printf("%d\n",sub(i));
    return 0;
}
int sub(int n)
{
    int a;
    if(n==1) return 1;
    a=n+sub(n-1);     
    return(a);
}
