#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 3e4+10;
int a[N];
int main() {
	int n, x;
	cin >> n;
	memset(a,INF,sizeof(a));
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		*upper_bound(a,a+n,x) = x;
	}
	printf("%d\n",lower_bound(a,a+n,INF)-a);
	return 0;
}