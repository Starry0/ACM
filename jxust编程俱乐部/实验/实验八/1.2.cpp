#include <stdio.h>
void increment()
{
   static int x=0;    
    x+=1;
    printf("%d",x);
}
int main()
{
  increment(); increment(); increment();
  return 0;
}
