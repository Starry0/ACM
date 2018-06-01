#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 33;
int a[N], ls[N][N][N], rs[N][N][N];
ll  fa[N][N][N];
int n;

ll dfs(int l, int r, int f) {
	if(fa[f][l][r]) return fa[f][l][r];
	fa[f][l][r] = a[f];
	ll lans, rans;
	for(int i = l; i < f; i ++) {
		lans = dfs(l,f-1,i);
		for(int j = f+1; j <= r; j ++) {
			rans = dfs(f+1,r,j);
			ll num = a[f] + lans*rans;
			if(num > fa[f][l][r]) {
				fa[f][l][r] = num;
				if(l != f)ls[f][l][r] = i;
				rs[f][l][r] = j;
			}
		}
	}
	if(l == f) {
		for(int j = f+1; j <= r; j ++) {
			ll num = a[f] + dfs(f+1, r, j);
			if(num > fa[f][l][r]) {
				fa[f][l][r] = num;
				rs[f][l][r] = j;
			}
		}
	}
	if(r == f){
		for(int i = l; i < f; i ++) {
			ll num = a[f] + dfs(l,f-1,i);
			if(num > fa[f][l][r]) {
				fa[f][l][r] = num;
				ls[f][l][r] = i;
			}
		}
	}
	return fa[f][l][r];
}
void print(int l, int r, int root) {
	printf("%d ",root);
	if(ls[root][l][r]) print(l,root-1,ls[root][l][r]);
	if(rs[root][l][r]) print(root+1,r,rs[root][l][r]);
}
int main() {
	ll root, MAX = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++) {
		ll ans = dfs(1,n,i);
		if(ans > MAX) {
			MAX = ans;
			root = i;
		}
	}
	cout << MAX << endl;
	print(1,n,root);
	return 0;
}