#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, a[N], b[N], tot;
int M = 1e9;
int main() {
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++) {
		if(a[i]&1) printf("%d ",a[i]);
		else printf("%d ",a[i]-1);
	}
	return 0;
}