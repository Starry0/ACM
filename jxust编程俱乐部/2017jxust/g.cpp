#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
#define ll long long
const int N = 1010;
using namespace std;
int n, k;
int vis[11], b[20];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < k; i ++) {
		int x; cin >> x;
		vis[x] = 1;
	}
	for(int i = n; ;i ++) {
		int k = 0, tmp = i;
		while(tmp) {
			b[k++] = tmp%10;;
			tmp /= 10;
		}
		bool flag = true;
		for(int j = 0; j < k; j ++) {
			if(vis[b[j]]) flag = false;
		}
		if(flag) return 0*printf("%d\n",i);
	}
	return 0;
}