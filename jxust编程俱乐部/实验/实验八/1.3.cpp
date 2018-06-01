#include <stdio.h>
int i=0;    
int workover(int i)   
{
    i=(i%i)*((i*i)/(2*i)+4);
    printf("i=%d\n",i);
    return(i);
}
int reset(int i)   
{
    i=i<=2?5:0;
    return(i);
}      
int main()
{
	
    int i=5;       
    reset(i/2);
    printf("i=%d\n",i);
    reset(i=i/2);
    printf("i=%d\n",i);
    reset(i/2);
    printf("i=%d\n",i);
    workover(i);
    printf("i=%d\n",i);
    return 0;
}

