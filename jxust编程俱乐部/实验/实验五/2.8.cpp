#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#define ll long long
using namespace std;
int main() {
	char str[100];
	ll x = 0, y = 0;
	bool flag = false, flag1 = false;
	scanf("%s", str);
	int len = strlen(str), i;
	for(i = 0; i < len; i ++) {
		if(i == 0) {
			if(str[i] == '-') flag = true;
			else if(str[i] == '+') flag = false;
			else if(str[i] >= '0' && str[i] <= '9') x = x*10 + str[i] - '0';
			else return 0*printf("Error: operator error.\n");
		}
		else if(!(str[i] >= '0' && str[i] <= '9')) break;
		else x = x*10 + str[i] - '0';
	}
	char c = str[i]; i ++;
	int k = i;
	for(; k < len; k ++) {
		if(k == i) {
			if(str[k] == '-') flag1 = true;
			else if(str[k] == '+') flag1 = false;
			else if(str[k] >= '0' && str[k] <= '9') y = y*10 + str[k] - '0';
			else return 0*printf("Error: operator error.\n");
		}
		else if(!(str[k] >= '0' && str[k] <= '9')) break;
		else y = y*10 + str[k] - '0';
	}
	if(flag) x *= -1;
	if(flag1) y *= -1;
	if(k != len) printf("Error: operator error.\n");
	else if(c == '/' && y == 0) printf("Error: divisor is zero.");
	else if(c == '-') printf("%lld\n", x - y);
	else if(c == '+') printf("%lld\n", x + y);
	else if(c == '*') printf("%lld\n", x * y);
	else if(c == '/') printf("%.4lf\n", 1.0*x / y);
	else printf("Error: operator error.\n");
    return 0;
}
