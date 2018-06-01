#include <stdio.h>
int main(){
	for(int i = 30; i < 100; i ++) {
		int x = i*i;
		if(x > 1000) {
			int a = x/1000, b = x/100%10, c = x/10%10, d = x%10;
			if(a==b && b != c && c == d) printf("%d\n",x);
		}
	}
	return 0;
}