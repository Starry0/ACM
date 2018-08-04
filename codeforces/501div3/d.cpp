#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
	ll n, k, s, t;
	cin >> n >> k >> s;
	if((n-1)*k < s || k > s) return 0*printf("NO\n");
	ll now = 1, pre = 1, flag = 1;
	t = k;
	printf("YES\n");
	for(int i = 1; i <= t; i ++) {
		if(i == t) {
			if(now+s <= n) return 0*printf("%d\n",now+s);
			else return 0*printf("%d\n",now-s);
		}
		if(s-n+1 >= k-1) {
			if(flag==1)now += n-1, flag = 2;
			else now -= n-1, flag = 1;
			s -= n-1;
		} else {
			if(now == 1) {
				now++;
			} else if(now == 2) now--;
			else if(now == n) now--;
			else if(now == n-1) now++;
			s --;
			// int cnt = s-k+1;
			// if(now-cnt >= 1) now -= cnt;
			// else if(now+cnt <= n) now += cnt;
			// s -= cnt;
		}
		k--;
		printf("%d ",now);
		pre = now;
	}
	return 0;
}