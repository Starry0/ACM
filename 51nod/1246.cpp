/*
5 12 12 : 2 2 2 3 3 为15  0 3 3 3 3 为13
求最少的空位
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, k, c;
	cin >> n >> k >> c;
	// printf("%d\n",c+max(0,n-k/((c-1)/n+1)));
	if(k/n*n >= c) printf("%d\n",c);
	else printf("%d\n",c+(n-k/(k/n+1)));
	return 0;
}