#include<stdio.h>
void shunum(int a)
{
 int i;
 for(i=2;i<=a;i++)
 {
  if(a%i==0)
  {
   printf("%d ",i);
   shunum(a/i);
   break;
  }
 }
}
int main()
{
 int i,j,n;
 printf("input a number:");
 scanf("%d",&n);
 shunum(n);
 return 0;
}
