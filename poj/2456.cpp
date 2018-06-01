#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N];
int n, c;
bool ok(int x) {
	int pre = a[0], ans = 1;
	for(int i = 1; i < n; i ++) {
		if(a[i] - pre >= x) {
			ans ++;
			pre = a[i];
		}
	}
	return ans >= c;
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
	//cin >> n >> c;
	//for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a, a+n);
	int l = 0, r = 1e9, ans;
	//printf("ok:%d\n",ok(2));
	while(l <= r) {
		int m = (l+r) >> 1;
		if(ok(m)) {
			ans = m;
			l = m+1;
		} else r = m - 1;
 	}
	printf("%d\n",ans);
	return 0;
}
//1 2 4 8 9