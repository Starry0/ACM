#include  <stdio.h>              
int main()
{
   int a;
   float b; 
   char c,ch1,ch2,ch3;
   scanf("%d,%f,%c",&a,&b,&c);
   printf("a=%d,b=%f,c=%c\n",a,b,c);
   getchar();
   scanf("%c,%c,%c",&ch1,&ch2,&ch3);
   printf("ch1=%c,ch2=%c,ch3=%c",ch1,ch2,ch3);
   return 0;
}
