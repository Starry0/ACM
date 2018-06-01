#include <stdio.h>
int main( )
{
int x=10; float pi=3.1416; 
printf("(1)%d\n",x); printf("(2)%6d\n",x);
printf("(3)%f\n",56.1);printf("(4)%5.14f\n",pi);
printf("(5)%e\n",568.1);printf("(6)%14.e\n",pi);
printf("(7)%g\n",pi); printf("(8)%12g\n",pi);
return 0;
}
