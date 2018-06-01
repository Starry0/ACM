#include <stdio.h>

int main() {
	char ch;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	while((ch = getchar()) != EOF) {
		if(ch == '\n') continue;
		else if(ch >= 'A' && ch <= 'Z') a++;
		else if(ch >= 'a' && ch <= 'z') b++;
		else if(ch >= '0' && ch <= '9') c++;
		else if(ch == ' ') d++;
		else e ++;
	}
	printf("%d\n%d\n%d\n%d\n%d\n",a,b,c,d,e);
    return 0;
}
