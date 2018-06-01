#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int t, a, b, n;
int p[110];
int main() {
	cin >> t;
	while(t--) {
		cin >> a >> b >> n;
		for(int i = 0; i < n; i ++) {
			cin >> p[i];
		}
		bool flag = true;
		for(int i = 0; i < n; i ++) {
			while(p[i] > 1 && b > 0) {
				p[i] -= 2;
				b--;
			}
			while(p[i] > 0 && a > 0) {
				p[i]--;
				a--;
			}
			if(p[i] != 0) {
				flag = false;
				break;
			}
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}