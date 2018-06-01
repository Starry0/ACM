#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
#define ll long long
const int N = 1010;
using namespace std;
ll h, w;
ll a[N][N];
int fun(int x, int y) {
	int ans = 0;
	if(x == 1 && y == 1) return 0;
	if(x == 1) {
		ans = 2*min(a[x][y-1],a[x][y]);
	} else {
		if(y == 1) {
			ans = 2*min(a[x][y],a[x-1][y]);
		} else {
			ans = 2*min(a[x][y],a[x-1][y]) + 2*min(a[x][y],a[x][y-1]);
		}
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> h >> w;
	for(int i = 1; i <= h; i ++) {
		for(int j = 1; j <= w; j ++) {
			cin >> a[i][j];
		}
	}
	ll sum = h*w*2;
	for(int i = 1; i <= h; i ++) {
		for(int j = 1; j <= w; j ++) {
			sum += a[i][j]*4;
			sum -= fun(i, j);
			//printf("%d %d --> %d   %d \n",i,j,fun(i,j),sum);
		}
	}
	cout << sum << endl;
	return 0;
}