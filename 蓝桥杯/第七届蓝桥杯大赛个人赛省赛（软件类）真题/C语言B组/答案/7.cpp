#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[13] = {1,2,3,4,5,6,7,8,9,10,11,12};
bool vis[13];
int ans;
void dfs(int x) {
	if(x == 5) {
		ans++;
		return;
	}
	for(int i = 0; i < 12; i ++) {
		if(!vis[i]) {
			vis[i] = true;
			dfs(x+1);
			vis[i] = false;
		}
	}
}
int main() {
	dfs(0);
	cout << ans << endl;
	return 0;
}