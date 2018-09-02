#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 105; i <= n; i ++) {
		if(i&1) {
			int cnt = 0;
			for(int j = 1; j <= n; j ++) if(i%j==0) cnt++;
			if(cnt == 8) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}