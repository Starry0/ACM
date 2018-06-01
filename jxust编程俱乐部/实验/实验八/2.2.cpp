#include <stdio.h>
int main()
{
    char c;
	c = getchar();
	if(c >= '0' && c <= '9') printf("1\n");
	else printf("0\n");
    return 0;
}
