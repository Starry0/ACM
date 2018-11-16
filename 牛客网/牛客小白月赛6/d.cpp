#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1000010;
char s[N];
int sum[N], a[30];
int main() {
	int n, m, x;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i = 1; i <= n; i ++) {
		a[s[i]-'a']++;
		sum[i] = a[s[i]-'a'];
	}
	while(m--) {
		scanf("%d",&x);
		printf("%d\n",sum[x]);
	}
    return 0;
}
