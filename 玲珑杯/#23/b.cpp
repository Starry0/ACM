#include <bits/stdc++.h>
using namespace std;
int str[22][22];
int a[10], b[10];
bool colrow() {
	for(int i = 1; i <= 9; i ++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(int j = 1; j <= 9; j ++) {
			a[str[i][j]] ++;
			b[str[j][i]] ++;
		}
		for(int i = 1; i < 10; i ++) {
			if(a[i] == 0 || b[i] == 0) return false;
		}
	}
	return true;
}
bool dujge(int x, int y) {
	memset(a, 0, sizeof(a));
	for(int i = x; i < x+3; i ++) {
		for(int j = y; j < y+3; j ++) {
			a[str[i][j]] ++;
		}
	}
	for(int i = 1; i < 10; i ++) {
		if(a[i] == 0) return false;
	}
	return true;
}
bool mid() {
	return dujge(1,1)&&dujge(1,4)&&dujge(1,7)&&dujge(4,1)&&dujge(4,4)&&dujge(4,7)&&dujge(7,1)&&dujge(7,4)&&dujge(7,7);
}
bool ok() {
	if(!colrow()) return false;
	if(!mid()) return false;
	return true;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		for(int i = 1; i < 10; i ++) {
			for(int j = 1; j < 10; j ++) cin >> str[i][j];
		}
		if(ok()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}