 #include <stdio.h>
int main()
{
int a,b,t;
scanf("%d,%d",&a,&b);
    printf("a=%d,b=%d\n",a,b);
t=a;    
a=b;
b=t;
    printf("a=%d,b=%d\n",a,b);  
    return 0;
}