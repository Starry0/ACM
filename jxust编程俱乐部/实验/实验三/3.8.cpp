#include <stdio.h>  
int main()
{
	float  x=3.6 ,y;
y=(x-=x*10,x*10) ;
	printf("x=%f,y=%d\n",x,y);
return 0;
}
