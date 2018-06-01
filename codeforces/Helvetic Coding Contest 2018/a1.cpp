#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char str[N][N], str1[N][N];
int n;
bool ok1() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[i][j])
				return false;
		}
	}
	return true;
}
bool ok2() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[j][n+1-i])
				return false;
		}
	}
	return true;
}
bool ok3() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[n+1-i][n+1-j])
				return false;
		}
	}
	return true;
}
bool ok4() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[n+1-j][i])
				return false;
		}
	}
	return true;
}bool ok5() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[i][n+1-j])
				return false;
		}
	}
	return true;
}
bool ok6() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[n+1-j][n+1-i])
				return false;
		}
	}
	return true;
}
bool ok7() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[n+1-i][j])
				return false;
		}
	}
	return true;
}
bool ok8() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(str[i][j] != str1[j][i])
				return false;
		}
	}
	return true;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> str[i]+1;
	for(int i = 1; i <= n; i ++) cin >> str1[i]+1;
	if(ok1()||ok2()||ok3()||ok4()||ok5()||ok6()||ok7()||ok8()) printf("Yes\n");
	else printf("No\n");
	return 0;
}