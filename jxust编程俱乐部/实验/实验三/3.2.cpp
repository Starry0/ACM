#include <stdio.h>
        int main()
{ 
int i=8,j=9,a=10,b=2;
a-=i++;
b+=--j;
printf("a=%d,b=%d\n",a,b);
printf("i=%d,j=%d\n",i,j);
return 0;
 }
