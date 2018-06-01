#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
map<int,int> mp;
int main() {
	int n, x;

	cin >> n;
	int MAX1 = 0, MAX2 = 0;
	for(int i = 0; i < n; i ++) {
		scanf("%d", &x);
		if(mp.count(x)) {
			if(x > MAX1) {
				MAX2 = MAX1;
				MAX1 = x;
			} else if(x > MAX2) {
				if(x == MAX1 && mp[x] >= 3) {
					MAX2 = x;
				} else if(x < MAX1) MAX2 = x;
			}
		}
		mp[x] ++;
	}
	printf("%lld\n",1LL*MAX1*MAX2);
	return 0;
}