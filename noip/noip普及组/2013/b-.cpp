#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;
char str[N];
int main() {
	ll sum = 0, tmp =0, flag = 0, tmp1 = 0;
	cin >> str;
	int len = strlen(str);
	str[len] = '+'; str[len+1] = '0';
	//cout << str << endl;
	for(int i = 0; str[i]; i ++) {
		if(str[i] == '+') {
			switch(flag) {
				case 0:
				case 1:
					sum += tmp;
					tmp = 0;
					break;
				case 2:
					sum += tmp*tmp1;
					tmp = tmp1 = 0;
					break;
			}
			//sum %= 10000;
			flag = 1;
		} else if(str[i] == '*') {
			switch(flag) {
				case 0:
				case 1:
					tmp1 = tmp;
					tmp = 0;
					break;
				case 2:
					tmp1 *= tmp;
					tmp = 0;
					break;
			}
			flag = 2;
		} else {
			tmp = str[i] - '0' + tmp * 10;
		}
	}
	printf("%lld\n",sum%10000);
	return 0;
}