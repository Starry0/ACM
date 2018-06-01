#include <bits/stdc++.h>
#define ll long long
const int N = 1e5+10;
using namespace std;
int a[N], b[N];
vector<int> vs[N];
int main() {
	int n, k, m, x;
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[a[i]%m]++;
		vs[a[i]%m].push_back(i);
	}
	for(int i = 0; i <= m; i ++) {
		int len = vs[i].size();
		if(len >= k) {
			printf("Yes\n");
			for(int j = 0; j < k-1; j ++) {
				printf("%d ",a[vs[i][j]]);
			}
			return 0*printf("%d\n",a[vs[i][k-1]]);
		}
	}
	printf("No\n");
	return 0;
}