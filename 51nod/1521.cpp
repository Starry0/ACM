//可以用二分查找小于x的第一个数和大于x的第一个数。
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 2e5+10;
bool vis[N];
int n, k, a, x, m, l, r;
int main() {
	cin >> n >> k >> a;
	cin >> m;
	int MAX = (n+1)/(a+1);
	int flag = -1;
	for(int i = 1; i <= m; i ++) {
		cin >> x;
		vis[x] = 1;
		for(l = x-1; l >= 1 && !vis[l]; l--);
		for(r = x+1; r <= n && !vis[r]; r++);
		MAX -= (r-l)/(a+1) - (x-l)/(a+1) - (r-x)/(a+1);
		if(MAX < k && flag == -1) {
			flag = i;
			break;
		}
	}
	cout << flag << endl;
	return 0;
}