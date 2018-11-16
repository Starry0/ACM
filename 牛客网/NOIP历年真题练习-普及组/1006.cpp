#include <bits/stdc++.h>
using namespace std;
const int N = 10100;

bool ok(int y) {
	if(y%4==0&&y%100!=0 || y%400==0) return true;
	return false;
}

int main() {
	int a, b, ans = 0;
	cin >> a >> b;
	for(int i = a/10000; i <= b/10000; i ++) {
		int y = i%10*1000+i/10%10*100+i/100%10*10+i/1000;
		y = y + i * 10000;
		if(y >= a && y <= b) {
			int d = y %100, m = y%10000/100;
			if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) {
				if(d <= 31) ans++;
			} else if(m==4||m==6||m==9||m==11) {
				if(d <= 30) ans++;
			} else if(m==2) {
				if(ok(i) && d <= 29) ans++;
				else if(!ok(i) && d <= 28) ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}