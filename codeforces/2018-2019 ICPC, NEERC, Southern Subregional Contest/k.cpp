#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], n, k, sum = 0;

int find(int x) {
	int l = 1, r = n;
	while(l <= r) {
		int m = (l +r)>>1;
		if(a[m] == x) return m;
		if(a[m] < x) l = m+1;
		else r = m - 1;
	}
	return -1;
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i] += a[i-1];		
	}
	if(a[n]%k != 0) return 0*printf("No\n");
	int num = a[n]/k;
	vector<int> v;
	for(int i = 1; i <= k; i ++) {
		int id = find(i*num);
		if(id == -1) return 0*printf("No\n");
		v.push_back(id);
	}
	printf("Yes\n%d",v[0]);
	for(int i = 1; i < v.size(); i ++) {
		printf(" %d",v[i]-v[i-1]);
	}
	return 0;
}