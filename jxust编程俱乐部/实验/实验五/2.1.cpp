#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[4];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	printf("%d %d %d\n",a[2],a[1],a[0]);
	return 0;
}
