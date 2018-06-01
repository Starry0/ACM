#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
char str[110];
int main() {
	while(gets(str)) {
		int len = strlen(str);
		bool flag = false;
		if(len == 8) {
			if(str[0] =='L' || str[0] == 'l')
			if(str[1] =='o' || str[1] == 'O')
			if(str[2] =='v' || str[2] == 'V')
			if(str[3] =='e' || str[3] == 'E')
			if(str[4] =='L' || str[4] == 'l')
			if(str[5] =='i' || str[5] == 'I')
			if(str[6] =='V' || str[6] == 'v')
			if(str[7] =='e' || str[7] == 'E')
				flag = true;
		}
		if(flag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}