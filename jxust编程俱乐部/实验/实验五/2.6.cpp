#include <stdio.h>
#include <iostream>
#include <algorithm>
int mo[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using namespace std;
bool isOk(int y) {
	if(y%4==0&&y%100!=0 || y%400==0) return true;
	else return false;
}
int main()
{
	int y, m, d, ans = 0;
	scanf("%d-%d-%d",&y, &m, &d);
	for(int i = 0; i < m-1; i ++) ans += mo[i];
	if(isOk(y) && m > 2) ans++;
	printf("%d\n",ans+d);
	return 0;
}
