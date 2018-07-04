#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char str[N];
int main() {
	int a, b, x;
	bool flag = 0;
	cin >> a >> b >> x;
	flag = (a>b);
	for(int i = 1; i <= x; i ++) {
		if(flag) {
			if(i&1) {
				str[i] = '0';
				a--;
			}
			else {
				str[i] = '1';
				b--;
			}
		} else {
			if(i&1) {
				str[i] = '1';
				b--;
			}
			else {
				str[i] = '0';
				a--;
			}
		}
		
	}
	//printf("%s %d %d\n",str+1,a,b);
	if(flag) {
		if(x&1) {
			printf("%s",str+1);
			for(int i = 0; i < a; i ++) printf("0");
			for(int i = 0; i < b; i ++) printf("1");	
		} else {
			printf("%s",str+1);
			for(int i = 0; i < b; i ++) printf("1");
			for(int i = 0; i < a; i ++) printf("0");	
		}
	} else {
		if(x&1) {
			//101
			printf("%s",str+1);
			for(int i = 0; i < b; i ++) printf("1");
			for(int i = 0; i < a; i ++) printf("0");			
		} else {
			//1010
			printf("%s",str+1);
			for(int i = 0; i < a; i ++) printf("0");
			for(int i = 0; i < b; i ++) printf("1");	
		}
	}
	
	return 0;
}