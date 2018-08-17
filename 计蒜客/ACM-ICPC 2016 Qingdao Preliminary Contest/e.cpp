#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
const ll MAX = 1e9+10;
ll a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d",&n);
		if(n&1) printf("Balanced\n");
		else printf("Bad\n");
	}
	return 0;
}