#include <iostream>
#include <windows.h> 
using namespace std;
int a[10], ans;
bool vis[10];
bool ok(int x, int y) {
	if(x == y-1 || x == y+1) return false;
	else return true;
}

void dfs(int x) {
	if(x == 10) {
		if(ok(a[0],a[1])&&ok(a[0],a[4])&&ok(a[0],a[5])&&ok(a[1],a[2])&&ok(a[1],a[5])&&ok(a[1],a[6])) {
			if(ok(a[2],a[6])&&ok(a[3],a[4])&&ok(a[3],a[7])&&ok(a[3],a[8])&&ok(a[4],a[5])&&ok(a[4],a[8])&&a[4],a[9]) {
				if(ok(a[5],a[6])&&ok(a[5],a[9])&&ok(a[7],a[8])&&ok(a[8],a[9])) {
					ans++;
				}
			}
		}
		return;
	}
	for(int i = 0; i < 10; i ++ ) {
		if(!vis[i]) {
			vis[i] = true;
			a[x] = i;
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