#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+10;
char s[N];
struct Nod{
	int num, val;
	Nod() {
		num = val = 0;
	}
}e[N];
int dp[N];
int main() {
	int n, k;
	while(cin >> n >> k){
		cin >> s;
		int l = 0, cnt = 0;
		while(l < n) {
			while(l < n && s[l] == '0') l++;
			if(l >= n) break;
			int res = 0;
			while(l < n && s[l] == '1') {
				l++;res++;
			}
			e[cnt].num = res;
			e[cnt].val = 0;
			if(res != l) e[cnt].val++;
			if(l != n) e[cnt].val++;
			cnt++;
		}
		if(k == 0) {
			if(s[0] == '1') printf("%d\n",e[0].num);
			else printf("0\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		k++;
		for(int i = 0; i < cnt; i ++) {
			for(int j = k; j >= 0; j --) {
				if(j >= e[i].val) {
					dp[j] = max(dp[j],dp[j-e[i].val]+e[i].num);
				}
			}
		}
		printf("%d\n",dp[k]);
		memset(s,0,sizeof(s));
	}
	return 0;
}