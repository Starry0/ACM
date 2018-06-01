#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1000010;
int a[N];
int n, k;
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a,a+n);
	if(k == *lower_bound(a,a+n,k)) printf("%d\n",lower_bound(a,a+n,k)-a+1);
	else printf("-1");
	return 0;
}