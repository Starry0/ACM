#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int a[N];

int main() {
	a[1] = a[2] = 1;
	for(int i = 3; i < N; i ++) {
		a[i] = a[i-a[i-1]] + a[i-1-a[i-2]];
		printf("%d: a%d+a%d=a%d %d+%d=%d\n",i,i-a[i-1],i-1-a[i-2],i,a[i-a[i-1]],a[i-1-a[i-2]],a[i]);
	}
	return 0;
}