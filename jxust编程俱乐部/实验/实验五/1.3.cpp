#include <stdio.h>
int main()
{
   int w=3,z=7,x=10;
    printf("%d\n",x>10 ? x+100:x-10);
    printf("%d\n",w++||z++);
    printf("%d\n",!w>z);
    printf("%d\n",w&&z);

    return 0;
}
