#include <stdio.h>
int main()
{
	int k=2;
	switch(k)
	{
		case 1:printf("%d",k++);
		case 2:printf("%d",k++);
	    case 3:printf("%d",k++);
  	    case 4:printf("%d",k++);break;
  	    default:printf("Full!\n");
	}
	printf("\nk=%d\n",k);
	return 0;
}
