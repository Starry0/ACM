#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10010;
int a[N];
typedef pair<int,int> P;
map<P,int> mp;
int main() {	
	int n, l, r, h, x, y;
	cin >> n >> l >> h >> r;
	while(r--) {
		cin >> x >> y;
		if(x > y) swap(x, y);
		if(mp.count(P(x,y))) continue;
		mp[P(x,y)]++;
		a[x+1]--, a[y]++;
	}
	int sum = 0;
	for(int i = 1; i <= n; i ++) {
		sum += a[i];
		printf("%d\n",sum+h);
	}
	return 0;
}