#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int n, m;
	cin >> m >> n;
	double ans = m*24+n*18.5;
	if(ans < 100) printf("%.2lf\n",ans);
	else if(ans < 200) printf("%.2lf\n", 100 + (ans - 100) * 0.9);
	else if(ans < 300) printf("%.2lf\n", 190 + (ans - 200) * 0.85);
	else if(ans < 500) printf("%.2lf\n", 275 + (ans - 300) * 0.8);
	else printf("%.2lf\n", 435 + (ans - 500) * 0.7);
	return 0;
}
