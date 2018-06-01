#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
	char c;
	int ans = 0,d = 0, o = 0, g = 0, e = 0;
	while((c=getchar())!=EOF){
		if(c == ' ' || c == '\n'){
			d=o=g=e=0;
			continue;
		}
		if(isalpha(c))
			c = tolower(c);
		
		if(c == 'd'){
			d=1;o=g=e=0;
		}else if(c == 'o' && o==0){
			if(d==1){
				o=1;g=e=0;
			}
		}else if(c == 'g' && g==0){
			if(d==1&& o==1){
				g=1;e=0;
			}
		}else if(c == 'e' && e==0){
			if(d==1&&o==1&&g==1){
				ans++;
				d=o=g=e=0;
			}
		}else {
			d=o=g=e=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}