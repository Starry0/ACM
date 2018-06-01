#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int fun(int x) {
	if(x == 0) return 0;
	if(x % 2 == 0) return fun(x/2);
	if(a[x]) return a[x];
	return fun(x/2) + fun(x/2 + 1);
}
void init() {
	a[1] = 1;
	for(int i = 2; i < N; i ++) {
		if(i%2 == 0) a[i] = a[i/2];
		else a[i] = fun(i);
	}
	for(int i = 1; i < N; i ++) {
		a[i] = max(a[i], a[i-1]);
	}
}
int main() {
	int t, n;
	init();
	scanf("%d", &t);
	while(t--) {	
		cin >> n;
		printf("%d\n",a[n]);
	}
	return 0;
}