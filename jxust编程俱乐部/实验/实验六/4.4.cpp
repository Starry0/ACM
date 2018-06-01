#include <stdio.h>
int main()
{
  int i;
  int a[10],*p=&a;
  for(i=0;i<10;i++)
    *p++=2*i;
  for(p=a;p<a+10;p++)
    printf("%d ",*p);
  printf("\n");
  for(i=0;i<10;i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
} 
