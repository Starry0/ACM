#include <bits/stdc++.h>
using namespace std;
int mo[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[9];
int ok(int y) {
	if(y%4==0 && y%100!= 0 || y%400 == 0) return 1;
	else return 0;
}
void judge(int x) {
	int index = 1;
	while(x) {
		a[index++] = x%10;
		x /= 10;
	}
	for(int i = 1; i <= 4; i ++) {
		if(a[i] != a[9-i]) return false;
	}
	return true;
}
int main() {
	int a, b, ans = 0;
	cin >> a >> b;
	int year1 = a/10000, month1 = a/100%100, day1 = a%100;
	int year2 = b/10000, month2 = b/100%100, day2 = b%100;
	for(int i = year1; i <= year2; i ++) {
		for(int j = 1; j <= 12; j ++) {
			if(i == year1 && j < month1) continue;
			for(int k = 1; k <= mo[j]+(ok(i)&&j==2 ?1:0); k ++) {
				//if(k == 32) cout << "--\n"; 
				if(i == year1 && j == month1 && k < day1) continue;
				int cnt = i*10000+j*100+k;
			//	printf("%d --\n", cnt);
				if(judge(cnt)) ans ++;
				if(i == year2 && j == month2 && k == day2) {
				//	printf("%d -%d -%d-\n", i, j, k);
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
}