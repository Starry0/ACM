#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1000010;
int a[N], n;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int ans = 0, cnt = 0;
	for(int i = 2; i <= n; i ++) {
		if(a[i] > a[i-1]) {
			cnt = 1;
		} else if(a[i] < a[i-1] && cnt == 1) {
			cnt = 0;
			ans++;
		}
	}
	printf("%d\n",ans);
    return 0;
}
