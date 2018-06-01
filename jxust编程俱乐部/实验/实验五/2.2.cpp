#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	char c;
	c = getchar();
	if(isalpha(c))printf("char\n");
	else if(isdigit(c))printf("number\n");
	else printf("other\n");
	return 0;
}
