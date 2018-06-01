#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char a[10];
	scanf("%s", &a);
	for(int i = 9; i >= 0; i--)
		printf("%c", a[i]);
	cout<<endl;
	return 0;
}