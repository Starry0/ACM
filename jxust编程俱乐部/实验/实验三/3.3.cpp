/*#include <stdio.h>
        int main()
{ 
float x=1,y;
y=++x*++x; 
printf("y=%f\n",y);
return 0;
 }
*/
#include <stdio.h>
int main()
{ 
float x=1,y,m,n;
m=++x;
n=++x;
y=m*n; 
printf("y=%f\n",y);
return 0;
}
