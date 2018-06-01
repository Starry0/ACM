#include <iostream>
#include <vector>
#include <stdio.h>
#define ll long long
using namespace std;
const int N = 1e3+10;
int n, fa[N];
vector<int> vs[N];
bool ok(int x) {
	int ans = vs[x].size();
	if(ans == 0) return true;
	ans = 0;
	for(int i = 0; i < vs[x].size(); i ++) {
		if(vs[vs[x][i]].size() == 0) ans++;
	}
	if(ans >= 3) return true;
	else return false;
}
int main() {
	int x;
	cin >> n;
	for(int i = 2; i <= n; i ++) {
		cin >> x;
		vs[x].push_back(i);
	}
	bool flag = true;
	for(int i = 1; i <= n; i ++) {
		if(!ok(i)) {
			flag = false;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}