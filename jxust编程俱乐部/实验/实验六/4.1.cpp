#include <stdio.h>
int main() {
	char ch;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f= 0;
	while((ch = getchar()) != '\n') {
		if(ch >= 'A' && ch <= 'Z') a++;
		else if(ch >= 'a' && ch <= 'z') b++;
		else if(ch == ' ') c++;
		else if(ch >= '0' && ch <= '9') d++;
		else e++;
	}
	printf("%d %d %d %d %d\n",a,b,c,d,e);
    return 0;
}
