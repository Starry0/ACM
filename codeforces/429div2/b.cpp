#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10;
int sum;
int main() {
	int n, x;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", &x);
		x %= 2;
		sum += x;
	}
	if(sum&1 || (sum%2==0 && sum > 0))printf("First\n");
	else printf("Second\n");
}