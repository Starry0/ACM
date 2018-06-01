#include <iostream>
#include <stdio.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6+10;
int a[N], b[N/10+10][5];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		if(!b[a[i]][0]) b[a[i]][1] = b[a[i]][2] = b[a[i]][3] = i;
		else {
			b[a[i]][2] = b[a[i]][3];
			b[a[i]][3] = i;
			b[a[i]][4] = max(b[a[i]][4], b[a[i]][3] - b[a[i]][2] - 1);			
		} 
		b[a[i]][0] ++;
	}
	int ans = INF;
	for(int i = 1; i <= n; i ++) {
		b[a[i]][4] = max(b[a[i]][4], n - b[a[i]][3] + b[a[i]][1] - 1);
		ans = min(ans, b[a[i]][4] + n);
	}
	printf("%d\n",ans);
	return 0;
}